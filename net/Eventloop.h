//
// Created by xqm on 2022/10/5.
//

#ifndef MYSERVER_EVENTLOOP_H
#define MYSERVER_EVENTLOOP_H
#include <vector>
#include <boost/scoped_ptr.hpp>

#include <base/Mutex.h>
//#include <base/CurrentThread.h>
#include <base/noncopyable.h>
#include <base/Thread.h>
#include <base/Timestamp.h>
#include <net/TimerId.h>
#include <net/Callbacks.h>

namespace x7m
{
namespace net
{

class Channel;
class Poller;
class TimerQueue;
///
/// Reactor, at most one per thread.
///
/// This is an interface class, so don't expose too much details.
class EventLoop : noncopyable {
public:
    typedef boost::function<void()> Functor;

    EventLoop();

    ~EventLoop();
    ///
    /// Loops forever.
    ///
    /// Must be called in the same thread as creation of the object.
    ///
    void loop();
    void quit();

    Timestamp pollReturnTime() const { return pollReturnTime_; }

    void runInLoop(const Functor& cb);
    void queueInLoop(const Functor& cb);

    TimerId runAt(const Timestamp& time, const TimerCallback& cb);
    TimerId runAfter(double delay, const TimerCallback& cb);
    TimerId runEvery(double interval, const TimerCallback& cb);
    void cancel(TimerId timerId);

    void wakeup();

    void updateChannel(Channel* channel);		// 在Poller中添加或者更新通道
    void removeChannel(Channel* channel);		// 从Poller中移除通道

    void assertInLoopThread() {
        if (!isInLoopThread()) {
            abortNotInLoopThread();
        }
    }

    bool isInLoopThread() const { return threadId_ == CurrentThread::tid(); }

    bool eventHandling() const { return eventHandling_; }

    static EventLoop* getEventLoopOfCurrentThread();

private:
    void abortNotInLoopThread();
    void handleRead();  // waked up
    void doPendingFunctors();

    void printActiveChannels() const; // DEBUG

    typedef std::vector<Channel*> ChannelList;

    bool looping_;/* atomic */
    bool quit_; /* atomic */
    bool eventHandling_; /* atomic */
    bool callingPendingFunctors_; /* atomic */

    const pid_t threadId_;		// 当前对象所属线程ID
    Timestamp pollReturnTime_;
    boost::scoped_ptr<Poller> poller_;
    boost::scoped_ptr<TimerQueue> timerQueue_;
    int wakeupFd_;				// 用于eventfd
    // unlike in TimerQueue, which is an internal class,
    // we don't expose Channel to client.
    boost::scoped_ptr<Channel> wakeupChannel_;	// 该通道将会纳入poller_来管理
    ChannelList activeChannels_;		// Poller返回的活动通道
    Channel* currentActiveChannel_;	// 当前正在处理的活动通道
    MutexLock mutex_;
    std::vector<Functor> pendingFunctors_; // @BuardedBy mutex_
};
} // net
} // x7m

#endif //MYSERVER_EVENTLOOP_H
