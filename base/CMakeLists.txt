set(    base_SRCS
        Condition.cpp
        CountDownLatch.cpp
        Exception.cpp
        FileUtil.cpp
        Logging.cpp
        LogStream.cpp
        LogFile.cpp
        ProcessInfo.cpp
        Thread.cpp
        ThreadPool.cpp
        Timestamp.cpp
)

add_library(myserver_base ${base_SRCS})
target_link_libraries(myserver_base pthread rt)

install(TARGETS myserver_base DESTINATION lib)
file(GLOB HEADERS "*.h")
install(FILES ${HEADERS} DESTINATION include/myserver/base)

if(NOT CMAKE_BUILD_NO_EXAMPLES)
    add_subdirectory(tests)
endif()
