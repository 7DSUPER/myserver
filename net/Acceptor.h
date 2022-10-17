//
// Created by xqm on 2022/10/16.
//

#ifndef MYSERVER_ACCEPTOR_H
#define MYSERVER_ACCEPTOR_H

#include <base/noncopyable.h>

#include <net/Channel.h>
#include <net/Socket.h>

namespace x7m
{
namespace net
{
class EventLoop;
class InetAddress;

///
/// Acceptor of incoming TCP connections.
///
class Acceptor : noncopyable
{
public:
    typedef std::function<void (int sockfd,
                                  const InetAddress&)> NewConnectionCallback;

    Acceptor(EventLoop *loop, const InetAddress &listenAddr);
    ~Acceptor();

    void setNewConnectionCallback(const NewConnectionCallback& cb)
    { newConnectionCallback_ = cb; }

    bool listenning() const { return listenning_; }
    void listen();

private:
    void handleRead();

    EventLoop* loop_;
    Socket acceptSocket_;
    Channel acceptChannel_;
    NewConnectionCallback newConnectionCallback_;
    bool listenning_;
    int idleFd_;
};

}
}
#endif //MYSERVER_ACCEPTOR_H
