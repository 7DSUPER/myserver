//
// Created by xqm on 2022/10/7.
//

#include "CountDownLatch.h"
using namespace x7m;

CountDownLatch::CountDownLatch(int count)
    :   mutex_(),
        condition_(mutex_),
        count_(count)
{
}

void CountDownLatch::wait()
{
    MutexLockGuard lock(mutex_);
    while (count_ > 0)
        condition_.wait();
}

void CountDownLatch::countDown()
{
    MutexLockGuard lock(mutex_);
    count_--;
    if (count_ == 0)
        condition_.notifyAll();
}

int CountDownLatch::getCount() const
{
    MutexLockGuard lock(mutex_);
    return count_;
}