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
include base/tests/CMakeFiles/Atomic_unittest.dir/depend.make

# Include the progress variables for this target.
include base/tests/CMakeFiles/Atomic_unittest.dir/progress.make

# Include the compile flags for this target's objects.
include base/tests/CMakeFiles/Atomic_unittest.dir/flags.make

base/tests/CMakeFiles/Atomic_unittest.dir/Atomic_unittest.cpp.o: base/tests/CMakeFiles/Atomic_unittest.dir/flags.make
base/tests/CMakeFiles/Atomic_unittest.dir/Atomic_unittest.cpp.o: ../base/tests/Atomic_unittest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xqm/myserver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object base/tests/CMakeFiles/Atomic_unittest.dir/Atomic_unittest.cpp.o"
	cd /home/xqm/myserver/cmake-build-debug/base/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Atomic_unittest.dir/Atomic_unittest.cpp.o -c /home/xqm/myserver/base/tests/Atomic_unittest.cpp

base/tests/CMakeFiles/Atomic_unittest.dir/Atomic_unittest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Atomic_unittest.dir/Atomic_unittest.cpp.i"
	cd /home/xqm/myserver/cmake-build-debug/base/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xqm/myserver/base/tests/Atomic_unittest.cpp > CMakeFiles/Atomic_unittest.dir/Atomic_unittest.cpp.i

base/tests/CMakeFiles/Atomic_unittest.dir/Atomic_unittest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Atomic_unittest.dir/Atomic_unittest.cpp.s"
	cd /home/xqm/myserver/cmake-build-debug/base/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xqm/myserver/base/tests/Atomic_unittest.cpp -o CMakeFiles/Atomic_unittest.dir/Atomic_unittest.cpp.s

# Object files for target Atomic_unittest
Atomic_unittest_OBJECTS = \
"CMakeFiles/Atomic_unittest.dir/Atomic_unittest.cpp.o"

# External object files for target Atomic_unittest
Atomic_unittest_EXTERNAL_OBJECTS =

bin/Atomic_unittest: base/tests/CMakeFiles/Atomic_unittest.dir/Atomic_unittest.cpp.o
bin/Atomic_unittest: base/tests/CMakeFiles/Atomic_unittest.dir/build.make
bin/Atomic_unittest: lib/libmyserver_base.a
bin/Atomic_unittest: base/tests/CMakeFiles/Atomic_unittest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xqm/myserver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/Atomic_unittest"
	cd /home/xqm/myserver/cmake-build-debug/base/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Atomic_unittest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
base/tests/CMakeFiles/Atomic_unittest.dir/build: bin/Atomic_unittest

.PHONY : base/tests/CMakeFiles/Atomic_unittest.dir/build

base/tests/CMakeFiles/Atomic_unittest.dir/clean:
	cd /home/xqm/myserver/cmake-build-debug/base/tests && $(CMAKE_COMMAND) -P CMakeFiles/Atomic_unittest.dir/cmake_clean.cmake
.PHONY : base/tests/CMakeFiles/Atomic_unittest.dir/clean

base/tests/CMakeFiles/Atomic_unittest.dir/depend:
	cd /home/xqm/myserver/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xqm/myserver /home/xqm/myserver/base/tests /home/xqm/myserver/cmake-build-debug /home/xqm/myserver/cmake-build-debug/base/tests /home/xqm/myserver/cmake-build-debug/base/tests/CMakeFiles/Atomic_unittest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : base/tests/CMakeFiles/Atomic_unittest.dir/depend
