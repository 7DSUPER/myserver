//
// Created by xqm on 2022/10/6.
//

#include "Exception.h"

#include <execinfo.h>
#include <stdlib.h>

using namespace x7m;

Exception::Exception(const char *what)
    :   message_(what)
{
    fillStackTrace();
}

Exception::Exception(string what)
    :   message_(std::move(what))
{
    fillStackTrace();
}

Exception::~Exception() throw ()
{
}
const char* Exception::what() const throw()
{
    return message_.c_str();
}
const char* Exception::stackTrace() const throw()
{
    return stack_.c_str();
}
void Exception::fillStackTrace()
{
    const int len = 200;
    void* buffer[len];
    int nptrs = ::backtrace(buffer, len);
    char** strings = ::backtrace_symbols(buffer, nptrs);
    if (strings)
    {
        for (int i = 0; i < nptrs; ++i)
        {
            // TODO demangle funcion name with abi::__cxa_demangle
            stack_.append(strings[i]);
            stack_.push_back('\n');
        }
        free(strings);
    }
}