# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/xqm/myserver

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xqm/myserver/cmake-build-debug

# Include any dependencies generated for this target.
include base/CMakeFiles/myserver_base.dir/depend.make

# Include the progress variables for this target.
include base/CMakeFiles/myserver_base.dir/progress.make

# Include the compile flags for this target's objects.
include base/CMakeFiles/myserver_base.dir/flags.make

base/CMakeFiles/myserver_base.dir/Condition.cpp.o: base/CMakeFiles/myserver_base.dir/flags.make
base/CMakeFiles/myserver_base.dir/Condition.cpp.o: ../base/Condition.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xqm/myserver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object base/CMakeFiles/myserver_base.dir/Condition.cpp.o"
	cd /home/xqm/myserver/cmake-build-debug/base && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/myserver_base.dir/Condition.cpp.o -c /home/xqm/myserver/base/Condition.cpp

base/CMakeFiles/myserver_base.dir/Condition.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/myserver_base.dir/Condition.cpp.i"
	cd /home/xqm/myserver/cmake-build-debug/base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xqm/myserver/base/Condition.cpp > CMakeFiles/myserver_base.dir/Condition.cpp.i

base/CMakeFiles/myserver_base.dir/Condition.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/myserver_base.dir/Condition.cpp.s"
	cd /home/xqm/myserver/cmake-build-debug/base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xqm/myserver/base/Condition.cpp -o CMakeFiles/myserver_base.dir/Condition.cpp.s

base/CMakeFiles/myserver_base.dir/CountDownLatch.cpp.o: base/CMakeFiles/myserver_base.dir/flags.make
base/CMakeFiles/myserver_base.dir/CountDownLatch.cpp.o: ../base/CountDownLatch.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xqm/myserver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object base/CMakeFiles/myserver_base.dir/CountDownLatch.cpp.o"
	cd /home/xqm/myserver/cmake-build-debug/base && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/myserver_base.dir/CountDownLatch.cpp.o -c /home/xqm/myserver/base/CountDownLatch.cpp

base/CMakeFiles/myserver_base.dir/CountDownLatch.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/myserver_base.dir/CountDownLatch.cpp.i"
	cd /home/xqm/myserver/cmake-build-debug/base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xqm/myserver/base/CountDownLatch.cpp > CMakeFiles/myserver_base.dir/CountDownLatch.cpp.i

base/CMakeFiles/myserver_base.dir/CountDownLatch.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/myserver_base.dir/CountDownLatch.cpp.s"
	cd /home/xqm/myserver/cmake-build-debug/base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xqm/myserver/base/CountDownLatch.cpp -o CMakeFiles/myserver_base.dir/CountDownLatch.cpp.s

base/CMakeFiles/myserver_base.dir/Exception.cpp.o: base/CMakeFiles/myserver_base.dir/flags.make
base/CMakeFiles/myserver_base.dir/Exception.cpp.o: ../base/Exception.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xqm/myserver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object base/CMakeFiles/myserver_base.dir/Exception.cpp.o"
	cd /home/xqm/myserver/cmake-build-debug/base && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/myserver_base.dir/Exception.cpp.o -c /home/xqm/myserver/base/Exception.cpp

base/CMakeFiles/myserver_base.dir/Exception.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/myserver_base.dir/Exception.cpp.i"
	cd /home/xqm/myserver/cmake-build-debug/base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xqm/myserver/base/Exception.cpp > CMakeFiles/myserver_base.dir/Exception.cpp.i

base/CMakeFiles/myserver_base.dir/Exception.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/myserver_base.dir/Exception.cpp.s"
	cd /home/xqm/myserver/cmake-build-debug/base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xqm/myserver/base/Exception.cpp -o CMakeFiles/myserver_base.dir/Exception.cpp.s

base/CMakeFiles/myserver_base.dir/Thread.cpp.o: base/CMakeFiles/myserver_base.dir/flags.make
base/CMakeFiles/myserver_base.dir/Thread.cpp.o: ../base/Thread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xqm/myserver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object base/CMakeFiles/myserver_base.dir/Thread.cpp.o"
	cd /home/xqm/myserver/cmake-build-debug/base && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/myserver_base.dir/Thread.cpp.o -c /home/xqm/myserver/base/Thread.cpp

base/CMakeFiles/myserver_base.dir/Thread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/myserver_base.dir/Thread.cpp.i"
	cd /home/xqm/myserver/cmake-build-debug/base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xqm/myserver/base/Thread.cpp > CMakeFiles/myserver_base.dir/Thread.cpp.i

base/CMakeFiles/myserver_base.dir/Thread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/myserver_base.dir/Thread.cpp.s"
	cd /home/xqm/myserver/cmake-build-debug/base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xqm/myserver/base/Thread.cpp -o CMakeFiles/myserver_base.dir/Thread.cpp.s

base/CMakeFiles/myserver_base.dir/ThreadPool.cpp.o: base/CMakeFiles/myserver_base.dir/flags.make
base/CMakeFiles/myserver_base.dir/ThreadPool.cpp.o: ../base/ThreadPool.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xqm/myserver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object base/CMakeFiles/myserver_base.dir/ThreadPool.cpp.o"
	cd /home/xqm/myserver/cmake-build-debug/base && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/myserver_base.dir/ThreadPool.cpp.o -c /home/xqm/myserver/base/ThreadPool.cpp

base/CMakeFiles/myserver_base.dir/ThreadPool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/myserver_base.dir/ThreadPool.cpp.i"
	cd /home/xqm/myserver/cmake-build-debug/base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xqm/myserver/base/ThreadPool.cpp > CMakeFiles/myserver_base.dir/ThreadPool.cpp.i

base/CMakeFiles/myserver_base.dir/ThreadPool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/myserver_base.dir/ThreadPool.cpp.s"
	cd /home/xqm/myserver/cmake-build-debug/base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xqm/myserver/base/ThreadPool.cpp -o CMakeFiles/myserver_base.dir/ThreadPool.cpp.s

base/CMakeFiles/myserver_base.dir/Timestamp.cpp.o: base/CMakeFiles/myserver_base.dir/flags.make
base/CMakeFiles/myserver_base.dir/Timestamp.cpp.o: ../base/Timestamp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xqm/myserver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object base/CMakeFiles/myserver_base.dir/Timestamp.cpp.o"
	cd /home/xqm/myserver/cmake-build-debug/base && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/myserver_base.dir/Timestamp.cpp.o -c /home/xqm/myserver/base/Timestamp.cpp

base/CMakeFiles/myserver_base.dir/Timestamp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/myserver_base.dir/Timestamp.cpp.i"
	cd /home/xqm/myserver/cmake-build-debug/base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xqm/myserver/base/Timestamp.cpp > CMakeFiles/myserver_base.dir/Timestamp.cpp.i

base/CMakeFiles/myserver_base.dir/Timestamp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/myserver_base.dir/Timestamp.cpp.s"
	cd /home/xqm/myserver/cmake-build-debug/base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xqm/myserver/base/Timestamp.cpp -o CMakeFiles/myserver_base.dir/Timestamp.cpp.s

# Object files for target myserver_base
myserver_base_OBJECTS = \
"CMakeFiles/myserver_base.dir/Condition.cpp.o" \
"CMakeFiles/myserver_base.dir/CountDownLatch.cpp.o" \
"CMakeFiles/myserver_base.dir/Exception.cpp.o" \
"CMakeFiles/myserver_base.dir/Thread.cpp.o" \
"CMakeFiles/myserver_base.dir/ThreadPool.cpp.o" \
"CMakeFiles/myserver_base.dir/Timestamp.cpp.o"

# External object files for target myserver_base
myserver_base_EXTERNAL_OBJECTS =

lib/libmyserver_base.a: base/CMakeFiles/myserver_base.dir/Condition.cpp.o
lib/libmyserver_base.a: base/CMakeFiles/myserver_base.dir/CountDownLatch.cpp.o
lib/libmyserver_base.a: base/CMakeFiles/myserver_base.dir/Exception.cpp.o
lib/libmyserver_base.a: base/CMakeFiles/myserver_base.dir/Thread.cpp.o
lib/libmyserver_base.a: base/CMakeFiles/myserver_base.dir/ThreadPool.cpp.o
lib/libmyserver_base.a: base/CMakeFiles/myserver_base.dir/Timestamp.cpp.o
lib/libmyserver_base.a: base/CMakeFiles/myserver_base.dir/build.make
lib/libmyserver_base.a: base/CMakeFiles/myserver_base.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xqm/myserver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX static library ../lib/libmyserver_base.a"
	cd /home/xqm/myserver/cmake-build-debug/base && $(CMAKE_COMMAND) -P CMakeFiles/myserver_base.dir/cmake_clean_target.cmake
	cd /home/xqm/myserver/cmake-build-debug/base && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/myserver_base.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
base/CMakeFiles/myserver_base.dir/build: lib/libmyserver_base.a

.PHONY : base/CMakeFiles/myserver_base.dir/build

base/CMakeFiles/myserver_base.dir/clean:
	cd /home/xqm/myserver/cmake-build-debug/base && $(CMAKE_COMMAND) -P CMakeFiles/myserver_base.dir/cmake_clean.cmake
.PHONY : base/CMakeFiles/myserver_base.dir/clean

base/CMakeFiles/myserver_base.dir/depend:
	cd /home/xqm/myserver/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xqm/myserver /home/xqm/myserver/base /home/xqm/myserver/cmake-build-debug /home/xqm/myserver/cmake-build-debug/base /home/xqm/myserver/cmake-build-debug/base/CMakeFiles/myserver_base.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : base/CMakeFiles/myserver_base.dir/depend
