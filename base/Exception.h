//
// Created by xqm on 2022/10/6.
//

#ifndef MYSERVER_EXCEPTION_H
#define MYSERVER_EXCEPTION_H

#include "Types.h"
//#include "CurrentThread.h"
#include <exception>

namespace x7m
{
class Exception : public std::exception
{
public:
    explicit Exception(const char* what);
    explicit Exception(string what);
    virtual ~Exception() throw();
    virtual const char* what() const throw();
    const char* stackTrace() const throw();

private:
    void fillStackTrace();

    string message_;
    string stack_;
};
} // namespace x7m

#endif //MYSERVER_EXCEPTION_H
