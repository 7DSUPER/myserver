//
// Created by xqm on 2022/10/5.
//

#ifndef MYSERVER_EVENTLOOP_H
#define MYSERVER_EVENTLOOP_H

#include "../base/Thread.h"
#include "../base/noncopyable.h"

namespace x7m
{
class EventLoop : noncopyable
{
public:

    EventLoop();
    ~EventLoop();

    void loop();

    void assertInLoopThread()
    {
        if (!isInLoopThread())
        {
            abortNotInLoopThread();
        }
    }

    bool isInLoopThread() const { return threadId_ == CurrentThread::tid(); }

private:
    void abortNotInLoopThread();
    bool looping_;
    const pid_t threadId_;
};

}

#endif //MYSERVER_EVENTLOOP_H
