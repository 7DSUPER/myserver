//
// Created by xqm on 2022/10/16.
//

#include "Socket.h"
#include "InetAddress.h"
#include "SocketsOps.h"
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <strings.h>  // bzero

using namespace x7m;
using namespace x7m::net;

Socket::~Socket()
{
    sockets::close(sockfd_);
}

void Socket::bindAddress(const InetAddress &localaddr)
{
    sockets::bindOrDie(sockfd_, localaddr.getSockAddrInet());

}

void Socket::listen()
{
    sockets::listenOrDie(sockfd_);
}

int Socket::accept(InetAddress *peeraddr)
{
    struct sockaddr_in addr;
    bzero(&addr, sizeof addr);
    int connfd = sockets::accept(sockfd_, &addr);
    if (connfd >= 0) {
        peeraddr->setSockAddrInet(addr);
    }
    return connfd;
}

void Socket::shutdownWrite()
{
    sockets::shutdownWrite(sockfd_);
}

void Socket::setTcpNoDelay(bool on)
{
    int optval = on ? 1 : 0;
    ::setsockopt(sockfd_, IPPROTO_TCP, TCP_NODELAY,
                 &optval, sizeof optval);
    // FIXME CHECK
}

void Socket::setReuseAddr(bool on)
{
    int optval = on ? 1 : 0;
    ::setsockopt(sockfd_, SOL_SOCKET, SO_REUSEADDR,
                 &optval, sizeof optval);
    // FIXME CHECK
}

void Socket::setKeepAlive(bool on)
{
    int optval = on ? 1 : 0;
    ::setsockopt(sockfd_, SOL_SOCKET, SO_KEEPALIVE,
                 &optval, sizeof optval);
    // FIXME CHECK
}