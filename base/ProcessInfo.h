//
// Created by xqm on 2022/10/10.
//

#ifndef MYSERVER_PROCESSINFO_H
#define MYSERVER_PROCESSINFO_H

#include "Types.h"
#include "Timestamp.h"
#include <vector>

namespace x7m {

namespace ProcessInfo
{
pid_t pid();
string pidString();
uid_t uid();
string username();
uid_t euid();
Timestamp startTime();

string hostname();

/// read /proc/self/status
string procStatus();

int openedFiles();
int maxOpenFiles();

int numThreads();
std::vector<pid_t> threads();
}

} // x7m

#endif //MYSERVER_PROCESSINFO_H
