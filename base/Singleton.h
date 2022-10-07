//
// Created by xqm on 2022/10/7.
//

#ifndef MYSERVER_SINGLETON_H
#define MYSERVER_SINGLETON_H

#include "noncopyable.h"
#include <pthread.h>
#include <stdlib.h> // atexit

namespace x7m
{

template <class T>
class Singleton : noncopyable
{
public:
    static T& instance()
    {
        pthread_once(&ponce_, &Singleton<T>::init);
        return *value_;
    }

private:
    Singleton();
    ~Singleton();

    static void init()
    {
        value_ = new T();
        ::atexit(destroy);
    }
    static void destroy()
    {
//        typedef char T_must_be_complete_type[sizeof(T) == 0 ? -1 : 1];
        delete value_;
    }

private:
    static pthread_once_t ponce_;
    static T* value_;
};

template<class T>
pthread_once_t Singleton<T>::ponce_ = PTHREAD_ONCE_INIT;

template<class T>
T* Singleton<T>::value_ = NULL;

}// namespace x7m

#endif //MYSERVER_SINGLETON_H
