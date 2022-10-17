//
// Created by xqm on 2022/10/13.
//

#ifndef MYSERVER_TIMER_H
#define MYSERVER_TIMER_H

#include <base/noncopyable.h>

#include <base/Atomic.h>
#include <base/Timestamp.h>
#include <net/Callbacks.h>

namespace x7m
{
namespace net
{
///
/// Internal class for timer event.
///
class Timer : noncopyable
{
public:
    Timer(TimerCallback cb, Timestamp when, double interval)
        : callback_(std::move(cb)),
          expiration_(when),
          interval_(interval),
          repeat_(interval > 0.0),
          sequence_(s_numCreated_.incrementAndGet())
    {}

    void run() const
    {
        callback_();
    }

    Timestamp expiration() const
    { return expiration_; }
    bool repeat() const
    { return repeat_; }
    int64_t sequence() const
    { return sequence_; }

    void restart(Timestamp now);

    static int64_t numCreated() { return s_numCreated_.get(); }

private:
    const TimerCallback callback_;		// 定时器回调函数
    Timestamp expiration_;				// 下一次的超时时刻
    const double interval_;				// 超时时间间隔，如果是一次性定时器，该值为0
    const bool repeat_;					// 是否重复
    const int64_t sequence_;				// 定时器序号
    static AtomicInt64 s_numCreated_;		// 定时器计数，当前已经创建的定时器数量
};
} // net
} // x7m

#endif //MYSERVER_TIMER_H
