//
// Created by xqm on 2022/10/5.
//

#ifndef MYSERVER_THREAD_H
#define MYSERVER_THREAD_H

#include "Atomic.h"
#include <functional>
#include "noncopyable.h"
#include <pthread.h>

namespace x7m
{
class Thread {
public:
    typedef std::function<void ()> ThreadFunc;
    explicit Thread(ThreadFunc, const std::string& name = std::string());
    ~Thread();

    void start();
    void join();

    bool started() const
    {
        return started_;
    }
    pid_t tid() const
    {
        return tid_;
    }
    const std::string &name() const
    {
        return name_;
    }
    static int numCreated()
    {
        return numCreated_.get();
    }

private:
    static void *startThread(void *thread);
    void runInThread();

    bool started_;
    pthread_t pthreadId_;
    pid_t tid_;
    ThreadFunc func_;
    std::string name_;

    static AtomicInt32 numCreated_;
};



} // namespace x7m



#endif //MYSERVER_THREAD_H
