//
// Created by xqm on 2022/10/12.
//

#ifndef MYSERVER_POLLER_H
#define MYSERVER_POLLER_H
#include <vector>
#include <base/noncopyable.h>

#include <base/Timestamp.h>
#include <net/Eventloop.h>

namespace x7m
{
namespace net
{

class Channel;

///
/// Base class for IO Multiplexing
///
/// This class doesn't own the Channel objects.
class Poller : noncopyable
{
public:
    typedef std::vector<Channel* > ChannelList;

    Poller(EventLoop *loop);
    virtual ~Poller();

    /// Polls the I/O events.
    /// Must be called in the loop thread.
    virtual Timestamp poll(int timeoutMs, ChannelList* activeChannels) = 0;

    /// Changes the interested I/O events.
    /// Must be called in the loop thread.
    virtual void updateChannel(Channel* channel) = 0;

    /// Remove the channel, when it destructs.
    /// Must be called in the loop thread.
    virtual void removeChannel(Channel* channel) = 0;

    static Poller* newDefaultPoller(EventLoop* loop);

    void assertInLoopThread()
    {
        ownerLoop_->assertInLoopThread();
    }

private:
    EventLoop* ownerLoop_;	// Poller所属EventLoop
};
} // net

} // x7m

#endif //MYSERVER_POLLER_H
