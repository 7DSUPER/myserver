# Install script for directory: /home/xqm/myserver/base

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/xqm/myserver/cmake-build-debug/lib/libmyserver_base.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/myserver/base" TYPE FILE FILES
    "/home/xqm/myserver/base/Atomic.h"
    "/home/xqm/myserver/base/BlockingQueue.h"
    "/home/xqm/myserver/base/BoundedBlockingQueue.h"
    "/home/xqm/myserver/base/Condition.h"
    "/home/xqm/myserver/base/CountDownLatch.h"
    "/home/xqm/myserver/base/CurrentThread.h"
    "/home/xqm/myserver/base/Exception.h"
    "/home/xqm/myserver/base/FileUtil.h"
    "/home/xqm/myserver/base/LogFile.h"
    "/home/xqm/myserver/base/LogStream.h"
    "/home/xqm/myserver/base/Logging.h"
    "/home/xqm/myserver/base/Mutex.h"
    "/home/xqm/myserver/base/ProcessInfo.h"
    "/home/xqm/myserver/base/Singleton.h"
    "/home/xqm/myserver/base/StringPiece.h"
    "/home/xqm/myserver/base/Thread.h"
    "/home/xqm/myserver/base/ThreadLocal.h"
    "/home/xqm/myserver/base/ThreadLocalSingleton.h"
    "/home/xqm/myserver/base/ThreadPool.h"
    "/home/xqm/myserver/base/Timestamp.h"
    "/home/xqm/myserver/base/Types.h"
    "/home/xqm/myserver/base/copyable.h"
    "/home/xqm/myserver/base/noncopyable.h"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/xqm/myserver/cmake-build-debug/base/tests/cmake_install.cmake")

endif()

