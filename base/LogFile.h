//
// Created by xqm on 2022/10/10.
//

#ifndef MYSERVER_LOGFILE_H
#define MYSERVER_LOGFILE_H

#include "Mutex.h"
#include "Types.h"
#include "noncopyable.h"
#include <boost/scoped_ptr.hpp>

namespace x7m {

class LogFile : noncopyable
{
public:
    LogFile(const string& basename,
            size_t rollSize,
            bool threadSafe = true,
            int flushInterval = 3);
    ~LogFile();

    void append(const char* logline, int len);
    void flush();

private:
    void append_unlocked(const char* logline, int len);

    static string getLogFileName(const string& basename, time_t* now);
    void rollFile();

    const string basename_;
    const size_t rollSize_;
    const int flushInterval_;

    int count_;

    boost::scoped_ptr<MutexLock> mutex_;
    time_t startOfPeriod_;
    time_t lastRoll_;
    time_t lastFlush_;
    class File;
    boost::scoped_ptr<File> file_;

    const static int kCheckTimeRoll_ = 1024;
    const static int kRollPerSeconds_ = 60*60*24;
};

} // x7m

#endif //MYSERVER_LOGFILE_H
