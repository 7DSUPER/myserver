//
// Created by xqm on 2022/10/5.
//

#ifndef MYSERVER_NONCOPYABLE_H
#define MYSERVER_NONCOPYABLE_H

namespace x7m
{

class noncopyable
{
public:
    noncopyable(const noncopyable&) = delete;
    void operator=(const noncopyable&) = delete;

protected:
    noncopyable() = default;
    ~noncopyable() = default;
};

} // namespace x7m

#endif //MYSERVER_NONCOPYABLE_H
