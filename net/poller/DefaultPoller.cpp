//
// Created by xqm on 2022/10/12.
//
#include <net/Poller.h>
#include <net/poller/PollPoller.h>
#include <net/poller/EPollPoller.h>

#include <stdlib.h>

using namespace x7m::net;

Poller* Poller::newDefaultPoller(EventLoop *loop)
{
    if (::getenv("MUDUO_USE_POLL")) {
        return new PollPoller(loop);
    }
    else {
        return new EPollPoller(loop);
    }
}