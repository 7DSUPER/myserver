//
// Created by xqm on 2022/10/12.
//

#ifndef MYSERVER_EPOLLPOLLER_H
#define MYSERVER_EPOLLPOLLER_H
#include <net/Poller.h>

#include <map>
#include <vector>

struct epoll_event;

namespace x7m
{
namespace net
{

///
/// IO Multiplexing with epoll(4).
///
class EPollPoller : Poller
{
public:
    EPollPoller(EventLoop *loop);
    virtual ~EPollPoller();

    virtual Timestamp poll(int timeoutMs, ChannelList *activeChannels);
    virtual void updateChannel(Channel* channel);
    virtual void removeChannel(Channel* channel);

private:
    static const int kInitEventListSize = 16;

    void fillActiveChannels(int numEvents,
                            ChannelList *activeChannels) const;

    void update(int operation, Channel *channel);

    typedef std::vector<struct epoll_event> EventList;
    typedef std::map<int, Channel*> ChannelMap;

    int epollfd_;
    EventList  events_;
    ChannelMap channels_;
};


} // net
} // x7m



#endif //MYSERVER_EPOLLPOLLER_H
