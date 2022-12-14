//
// Created by xqm on 2022/10/9.
//

#ifndef MYSERVER_LOGGING_H
#define MYSERVER_LOGGING_H

#include "Timestamp.h"
#include "LogStream.h"

namespace x7m {

class Logger {
public:
    enum LogLevel
    {
        TRACE,
        DEBUG,
        INFO,
        WARN,
        ERROR,
        FATAL,
        NUM_LOG_LEVELS,
    };

    class SourceFile
    {
    public:
        template<int N>
        inline SourceFile(const char (&arr)[N]) :   data_(arr),
                                                    size_(N - 1)
        {
            const char* slash = strrchr(data_, '/'); // builtin function
            if (slash)
            {
                data_ = slash + 1;
                size_ -= static_cast<int>(data_ - arr);
            }
        }

        const char* data_;
        int size_;
    };

    Logger(SourceFile file, int line);
    Logger(SourceFile file, int line, LogLevel level);
    Logger(SourceFile file, int line, LogLevel level, const char* func);
    Logger(SourceFile file, int line, bool toAbort);
    ~Logger();

    LogStream& stream() { return impl_.stream_; }

    static LogLevel logLevel();
    static void setLogLevel(LogLevel level);

    typedef void (*OutputFunc)(const char* msg, int len);
    typedef void (*FlushFunc)();
    static void setOutput(OutputFunc);
    static void setFlush(FlushFunc);

private:
    class Impl
    {
    public:
        typedef Logger::LogLevel LogLevel;
        Impl(LogLevel level, int old_errno, const SourceFile& file, int line);
        void formatTime();
        void finish();

        Timestamp time_;
        LogStream stream_;
        LogLevel level_;
        int line_;
        SourceFile basename_;
    };

    Impl impl_;

};

extern Logger::LogLevel g_logLevel;

inline Logger::LogLevel Logger::logLevel()
{
    return g_logLevel;
}

#define LOG_TRACE if (x7m::Logger::logLevel() <= x7m::Logger::TRACE) \
  x7m::Logger(__FILE__, __LINE__, x7m::Logger::TRACE, __func__).stream()
#define LOG_DEBUG if (x7m::Logger::logLevel() <= x7m::Logger::DEBUG) \
  x7m::Logger(__FILE__, __LINE__, x7m::Logger::DEBUG, __func__).stream()
#define LOG_INFO if (x7m::Logger::logLevel() <= x7m::Logger::INFO) \
  x7m::Logger(__FILE__, __LINE__).stream()
#define LOG_WARN x7m::Logger(__FILE__, __LINE__, x7m::Logger::WARN).stream()
#define LOG_ERROR x7m::Logger(__FILE__, __LINE__, x7m::Logger::ERROR).stream()
#define LOG_FATAL x7m::Logger(__FILE__, __LINE__, x7m::Logger::FATAL).stream()
#define LOG_SYSERR x7m::Logger(__FILE__, __LINE__, false).stream()
#define LOG_SYSFATAL x7m::Logger(__FILE__, __LINE__, true).stream()

const char* strerror_tl(int savedErrno);

// Taken from glog/logging.h
//
// Check that the input is non NULL.  This very useful in constructor
// initializer lists.

#define CHECK_NOTNULL(val) \
  ::x7m::CheckNotNull(__FILE__, __LINE__, "'" #val "' Must be non NULL", (val))

// A small helper for CHECK_NOTNULL().
template <typename T>
T* CheckNotNull(Logger::SourceFile file, int line, const char *names, T* ptr) {
    if (ptr == NULL) {
        Logger(file, line, Logger::FATAL).stream() << names;
    }
    return ptr;
}
} // x7m

#endif //MYSERVER_LOGGING_H
