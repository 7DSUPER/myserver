//
// Created by xqm on 2022/10/12.
//

#ifndef MYSERVER_POLLPOLLER_H
#define MYSERVER_POLLPOLLER_H

#include <net/Poller.h>

#include <map>
#include <vector>

struct pollfd;

namespace x7m {
namespace net {

///
/// IO Multiplexing with poll(2).
///
class PollPoller : public Poller
{
public:
    PollPoller(EventLoop* loop);
    virtual ~PollPoller();

    virtual Timestamp poll(int timeoutMs, ChannelList* activeChannels);
    virtual void updateChannel(Channel* channel);
    virtual void removeChannel(Channel* channel);

private:
    void fillActiveChannels(int numEvents,
                            ChannelList* activeChannels) const;
    typedef std::vector<struct pollfd> PollFdList;
    typedef std::map<int, Channel*> ChannelMap;	// key是文件描述符，value是Channel*
    PollFdList pollfds_;
    ChannelMap channels_;
};
} // net
} // x7m
#endif //MYSERVER_POLLPOLLER_H
