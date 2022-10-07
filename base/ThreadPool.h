//
// Created by xqm on 2022/10/7.
//

#ifndef MYSERVER_THREADPOOL_H
#define MYSERVER_THREADPOOL_H

#include "Condition.h"
#include "Mutex.h"
#include "Thread.h"
#include "Types.h"
#include "noncopyable.h"
#include <boost/function.hpp>
#include <boost/ptr_container/ptr_vector.hpp>
#include <deque>

namespace x7m
{
class ThreadPool :noncopyable
{
public:
    typedef boost::function<void ()> Task;

    explicit ThreadPool(const std::string &name = std::string());

    ~ThreadPool();

    void start(int numThreads);

    void stop();

    void run(const Task &task);

private:
    void runInThread();
    Task take();

    MutexLock mutex_;
    Condition cond_;
    std::string name_;
    boost::ptr_vector<x7m::Thread> threads_;
    std::deque<Task> queue_;
    bool running_;
};
}

#endif //MYSERVER_THREADPOOL_H
