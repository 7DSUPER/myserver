//
// Created by xqm on 2022/10/7.
//

#ifndef MYSERVER_CURRENTTHREAD_H
#define MYSERVER_CURRENTTHREAD_H

namespace x7m
{
namespace CurrentThread
{
extern __thread int t_cachedTid;
extern __thread char t_tidString[32];
extern __thread const char* t_threadName;

void cacheTid();

inline int tid()
{
    if (t_cachedTid == 0)
        cacheTid();
    return t_cachedTid;
}

inline const char* tidString() // for logging
{
    return t_tidString;
}

inline const char* name()
{
    return t_threadName;
}

bool isMainThread();
}
}

#endif //MYSERVER_CURRENTTHREAD_H
