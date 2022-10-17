//
// Created by xqm on 2022/10/13.
//

#include "Timer.h"
using namespace x7m;
using namespace x7m::net;

AtomicInt64 Timer::s_numCreated_;

void Timer::restart(Timestamp now)
{
    if (repeat_)
    {
        // 重新计算下一个超时时刻
        expiration_ = addTime(now, interval_);
    }
    else
    {
        expiration_ = Timestamp::invalid();
    }
}
