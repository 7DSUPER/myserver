set(    base_SRCS
        Condition.cpp
        CountDownLatch.cpp
        Exception.cpp
        Thread.cpp
        ThreadPool.cpp
        Timestamp.cpp
)

add_library(myserver_base ${base_SRCS})
target_link_libraries(myserver_base pthread rt)

install(TARGETS myserver_base DESTINATION include/x7m/base)

if(NOT CMAKE_BUILD_NO_EXAMPLES)
    add_subdirectory(tests)
endif()
