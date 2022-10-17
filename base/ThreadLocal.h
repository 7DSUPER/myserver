//
// Created by xqm on 2022/10/8.
//

#ifndef MYSERVER_THREADLOCAL_H
#define MYSERVER_THREADLOCAL_H

#include "noncopyable.h"
#include <pthread.h>

namespace x7m
{
template <typename T>
class ThreadLocal : noncopyable
{
public:
    ThreadLocal()
    {
        pthread_key_create(&pkey_, &ThreadLocal::destructor);
    }
    ~ThreadLocal()
    {
        pthread_key_delete(pkey_);
    }
    T &value()
    {
        T *perThreadValue = static_cast<T*>(pthread_getspecific(pkey_));
        if (!perThreadValue) {
            T* newObj = new T();
            pthread_setspecific(pkey_, newObj);
            perThreadValue = newObj;
        }
        return *perThreadValue;
    }

private:
    static void destructor(void *x)
    {
        T *obj = static_cast<T*>(x);
//        typedef char T_must_be_complete_type[sizeof(T) == 0 ? -1 : 1];
        delete obj;
    }

private:
    pthread_key_t pkey_;
};
}

#endif //MYSERVER_THREADLOCAL_H
