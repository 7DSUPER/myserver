//
// Created by xqm on 2022/10/7.
//

#ifndef MYSERVER_CONDITION_H
#define MYSERVER_CONDITION_H

#include "noncopyable.h"
#include "Mutex.h"
#include <pthread.h>

namespace x7m
{
class Condition : noncopyable
{
public:
    explicit Condition(MutexLock &mutex) : mutex_(mutex)
    {
        pthread_cond_init(&pcond_, NULL);
    }
    ~Condition()
    {
        pthread_cond_destroy(&pcond_);
    }
    void wait()
    {
        pthread_cond_wait(&pcond_, mutex_.getPthreadMutex());
    }
    bool waitForSeconds(int seconds);
    void notify()
    {
        pthread_cond_signal(&pcond_);
    }
    void notifyAll()
    {
        pthread_cond_broadcast(&pcond_);
    }

private:
    MutexLock &mutex_;
    pthread_cond_t pcond_;
};

}

#endif //MYSERVER_CONDITION_H
