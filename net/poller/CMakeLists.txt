set(net_SRCS
  Channel.cpp
  EventLoop.cpp
  Poller.cpp
  poller/DefaultPoller.cpp
  poller/EPollPoller.cpp
  poller/PollPoller.cpp
  )

add_library(myserver_net ${net_SRCS})
target_link_libraries(myserver_net myserver_base)

install(TARGETS myserver_net DESTINATION lib)
set(HEADERS
  Channel.h
  EventLoop.h
  )
install(FILES ${HEADERS} DESTINATION include/myserver/net)

#add_subdirectory(http)
#add_subdirectory(inspect)
#
#if(NOT CMAKE_BUILD_NO_EXAMPLES)
#  add_subdirectory(tests)
#endif()
#
#if(PROTOBUF_FOUND)
#  add_subdirectory(protorpc)
#else()
#  add_subdirectory(protorpc EXCLUDE_FROM_ALL)
#endif()
