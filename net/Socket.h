//
// Created by xqm on 2022/10/16.
//

#ifndef MYSERVER_SOCKET_H
#define MYSERVER_SOCKET_H

#include <base/noncopyable.h>

namespace x7m
{
///
/// TCP networking.
///
namespace net
{

class InetAddress;

///
/// Wrapper of socket file descriptor.
///
/// It closes the sockfd when desctructs.
/// It's thread safe, all operations are delagated to OS.
class Socket : noncopyable
{
public:
    explicit Socket(int sockfd)
            : sockfd_(sockfd)
    { }

    ~Socket();
    int fd() const { return sockfd_; }
    void bindAddress(const InetAddress& localaddr);
    void listen();

    int accept(InetAddress* peeraddr);
    void shutdownWrite();
    // Nagle算法可以一定程度上避免网络拥塞
    // TCP_NODELAY选项可以禁用Nagle算法
    // 禁用Nagle算法，可以避免连续发包出现延迟，这对于编写低延迟的网络服务很重要
    void setTcpNoDelay(bool on);
    void setReuseAddr(bool on);
    // TCP keepalive是指定期探测连接是否存在，如果应用层有心跳的话，这个选项不是必需要设置的
    void setKeepAlive(bool on);

private:
    const int sockfd_;
};

}
}

#endif //MYSERVER_SOCKET_H
