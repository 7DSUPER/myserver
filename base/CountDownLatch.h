//
// Created by xqm on 2022/10/7.
//

#ifndef MYSERVER_COUNTDOWNLATCH_H
#define MYSERVER_COUNTDOWNLATCH_H

#include "Condition.h"
#include "Mutex.h"
#include "noncopyable.h"

namespace x7m
{
class CountDownLatch : noncopyable
{
public:
    explicit CountDownLatch(int count);

    void wait();

    void countDown();

    int getCount() const;

private:
    mutable MutexLock mutex_;
    Condition condition_;
    int count_;
};

} // namespace x7m


#endif //MYSERVER_COUNTDOWNLATCH_H
