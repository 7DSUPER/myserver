//
// Created by xqm on 2022/10/13.
//

#ifndef MYSERVER_CALLBACKS_H
#define MYSERVER_CALLBACKS_H

#include <boost/function.hpp>
#include <boost/shared_ptr.hpp>

#include <base/Timestamp.h>

namespace x7m
{

namespace net
{

class TcpConnection;
typedef boost::shared_ptr<TcpConnection> TcpConnectionPtr;

typedef boost::function<void()> TimerCallback;

typedef boost::function<void (const TcpConnectionPtr&)> ConnectionCallback;

typedef boost::function<void (const TcpConnectionPtr&,
                              const char* data,
                              ssize_t len)> MessageCallback;
} // net
} // x7m

#endif //MYSERVER_CALLBACKS_H
