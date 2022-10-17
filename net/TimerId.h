//
// Created by xqm on 2022/10/13.
//

#ifndef MYSERVER_TIMERID_H
#define MYSERVER_TIMERID_H

#include <base/copyable.h>
#include <stdint.h>

namespace x7m
{
namespace net
{
class Timer;

class TimerId : public copyable
{
public:
    TimerId()
        : timer_(nullptr),
          sequence_(0)
    {}

    TimerId(Timer *timer, int64_t seq)
        : timer_(timer),
          sequence_(seq)
    {}

    friend class TimerQueue;

private:
    Timer *timer_;
    int64_t sequence_;
};
}
}

#endif //MYSERVER_TIMERID_H
