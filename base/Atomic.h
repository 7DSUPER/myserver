//
// Created by xqm on 2022/10/5.
//

#ifndef MYSERVER_ATOMIC_H
#define MYSERVER_ATOMIC_H

#include "noncopyable.h"
#include <stdint.h>

namespace x7m
{
namespace detail
{
template<typename T>
class AtomicIntegerT : noncopyable
{
public:
    AtomicIntegerT()
        : value_(0)
    {
    }

    T get()
    {
        return __atomic_load_n(&value_, __ATOMIC_SEQ_CST);
    }

    T getAndAdd(T x)
    {
        return __atomic_fetch_add(&value_, x, __ATOMIC_SEQ_CST);
    }

    T addAndGet(T x)
    {
        return getAndAdd(x) + x;
    }

    T incrementAndGet()
    {
        return addAndGet(1);
    }

    T decrementAndGet()
    {
        return addAndGet(-1);
    }

    void add(T x)
    {
        getAndAdd(x);
    }

    void increment()
    {
        incrementAndGet();
    }

    void decrement()
    {
        decrementAndGet();
    }

    T getAndSet(T newValue)
    {
        return __atomic_exchange_n(&value_, newValue, __ATOMIC_SEQ_CST);
    }

private:
    volatile T value_;
};

} // namespace detail

typedef detail::AtomicIntegerT<int32_t> AtomicInt32;
typedef detail::AtomicIntegerT<int64_t> AtomicInt64;
} // namespace x7m


#endif //MYSERVER_ATOMIC_H
