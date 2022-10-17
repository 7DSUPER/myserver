//
// Created by xqm on 2022/10/12.
//

#include "Poller.h"

using namespace x7m;
using namespace x7m::net;

Poller::Poller(EventLoop *loop)
    :   ownerLoop_(loop)
{}

Poller::~Poller() = default;
