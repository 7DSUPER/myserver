//
// Created by xqm on 2022/10/5.
//

#include "Thread.h"
#include "CurrentThread.h"
#include "Exception.h"
//#include "Logging.h"
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <cassert>
#include <linux/unistd.h>

namespace x7m
{

namespace CurrentThread
{
    __thread int t_cachedTid = 0;
    __thread char t_tidString[32];
    __thread const char* t_threadName = "unknown";
} // namespace CurrentThread


namespace detail
{

pid_t gettid()
{
    return static_cast<pid_t>(::syscall(SYS_gettid));
}

void afterFork()
{
    CurrentThread::t_cachedTid = 0;
    CurrentThread::t_threadName = "main";
    CurrentThread::tid();
    // no need to call pthread_atfork(NULL, NULL, &afterFork);
}

class ThreadNameInitializer
{
public:
    ThreadNameInitializer()
    {
        x7m::CurrentThread::t_threadName = "main";
        pthread_atfork(NULL, NULL, &afterFork);
    }
};

ThreadNameInitializer init;
} // namespace detail

void CurrentThread::cacheTid()
{
    if (t_cachedTid == 0)
    {
        t_cachedTid = detail::gettid();
        int n = snprintf(t_tidString, sizeof t_tidString, "%5d ", t_cachedTid);
        assert(n == 6); (void) n;
    }
}

bool CurrentThread::isMainThread()
{
    return tid() == ::getpid();
}


AtomicInt32 Thread::numCreated_;

Thread::Thread(ThreadFunc func, const std::string &name)
    :   started_(false),
        pthreadId_(0),
        tid_(0),
        func_(std::move(func)),
        name_(name)
{
    numCreated_.increment();
}

Thread::~Thread()
{
}

void Thread::start()
{
    assert(!started_);
    started_ = true;
    errno = pthread_create(&pthreadId_, NULL, &startThread, this);
    if (errno != 0)
    {
//        LOG_SYSFATAL << "Failed in pthread_create";
    }}

void Thread::join()
{
    assert(started_);
    pthread_join(pthreadId_, NULL);
}
void* Thread::startThread(void* obj)
{
    Thread* thread = static_cast<Thread*>(obj);
    thread->runInThread();
    return NULL;
}

void Thread::runInThread()
{
    tid_ = CurrentThread::tid();
    CurrentThread::t_threadName = name_.c_str();
    try
    {
        func_();
        CurrentThread::t_threadName = "finished";
    }
    catch (const Exception& ex)
    {
        CurrentThread::t_threadName = "crashed";
        fprintf(stderr, "exception caught in Thread %s\n", name_.c_str());
        fprintf(stderr, "reason: %s\n", ex.what());
        fprintf(stderr, "stack trace: %s\n", ex.stackTrace());
        abort();
    }
    catch (const std::exception& ex)
    {
        CurrentThread::t_threadName = "crashed";
        fprintf(stderr, "exception caught in Thread %s\n", name_.c_str());
        fprintf(stderr, "reason: %s\n", ex.what());
        abort();
    }
    catch (...)
    {
        CurrentThread::t_threadName = "crashed";
        fprintf(stderr, "unknown exception caught in Thread %s\n", name_.c_str());
        throw; // rethrow
    }
}
} // namespace x7m