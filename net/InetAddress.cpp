//
// Created by xqm on 2022/10/16.
//

#include "InetAddress.h"
#include "Endian.h"
#include "SocketsOps.h"

#include <strings.h>  // bzero
#include <netinet/in.h>

#include <boost/static_assert.hpp>

// INADDR_ANY use (type)value casting.
#pragma GCC diagnostic ignored "-Wold-style-cast"
static const in_addr_t kInaddrAny = INADDR_ANY;
#pragma GCC diagnostic error "-Wold-style-cast"

using namespace x7m;
using namespace x7m::net;

BOOST_STATIC_ASSERT(sizeof(InetAddress) == sizeof(struct sockaddr_in));

InetAddress::InetAddress(uint16_t port)
{
    bzero(&addr_, sizeof addr_);
    addr_.sin_family = AF_INET;
    addr_.sin_addr.s_addr = sockets::hostToNetwork32(kInaddrAny);
    addr_.sin_port = sockets::hostToNetwork16(port);
}

InetAddress::InetAddress(const StringPiece& ip, uint16_t port)
{
    bzero(&addr_, sizeof addr_);
    sockets::fromIpPort(ip.data(), port, &addr_);
}

string InetAddress::toIpPort() const
{
    char buf[32];
    sockets::toIpPort(buf, sizeof buf, addr_);
    return buf;
}

string InetAddress::toIp() const
{
    char buf[32];
    sockets::toIp(buf, sizeof buf, addr_);
    return buf;
}
