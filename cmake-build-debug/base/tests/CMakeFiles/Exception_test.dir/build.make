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
include base/tests/CMakeFiles/Exception_test.dir/depend.make

# Include the progress variables for this target.
include base/tests/CMakeFiles/Exception_test.dir/progress.make

# Include the compile flags for this target's objects.
include base/tests/CMakeFiles/Exception_test.dir/flags.make

base/tests/CMakeFiles/Exception_test.dir/Exception_test.cpp.o: base/tests/CMakeFiles/Exception_test.dir/flags.make
base/tests/CMakeFiles/Exception_test.dir/Exception_test.cpp.o: ../base/tests/Exception_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xqm/myserver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object base/tests/CMakeFiles/Exception_test.dir/Exception_test.cpp.o"
	cd /home/xqm/myserver/cmake-build-debug/base/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Exception_test.dir/Exception_test.cpp.o -c /home/xqm/myserver/base/tests/Exception_test.cpp

base/tests/CMakeFiles/Exception_test.dir/Exception_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Exception_test.dir/Exception_test.cpp.i"
	cd /home/xqm/myserver/cmake-build-debug/base/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xqm/myserver/base/tests/Exception_test.cpp > CMakeFiles/Exception_test.dir/Exception_test.cpp.i

base/tests/CMakeFiles/Exception_test.dir/Exception_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Exception_test.dir/Exception_test.cpp.s"
	cd /home/xqm/myserver/cmake-build-debug/base/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xqm/myserver/base/tests/Exception_test.cpp -o CMakeFiles/Exception_test.dir/Exception_test.cpp.s

# Object files for target Exception_test
Exception_test_OBJECTS = \
"CMakeFiles/Exception_test.dir/Exception_test.cpp.o"

# External object files for target Exception_test
Exception_test_EXTERNAL_OBJECTS =

bin/Exception_test: base/tests/CMakeFiles/Exception_test.dir/Exception_test.cpp.o
bin/Exception_test: base/tests/CMakeFiles/Exception_test.dir/build.make
bin/Exception_test: lib/libmyserver_base.a
bin/Exception_test: base/tests/CMakeFiles/Exception_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xqm/myserver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/Exception_test"
	cd /home/xqm/myserver/cmake-build-debug/base/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Exception_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
base/tests/CMakeFiles/Exception_test.dir/build: bin/Exception_test

.PHONY : base/tests/CMakeFiles/Exception_test.dir/build

base/tests/CMakeFiles/Exception_test.dir/clean:
	cd /home/xqm/myserver/cmake-build-debug/base/tests && $(CMAKE_COMMAND) -P CMakeFiles/Exception_test.dir/cmake_clean.cmake
.PHONY : base/tests/CMakeFiles/Exception_test.dir/clean

base/tests/CMakeFiles/Exception_test.dir/depend:
	cd /home/xqm/myserver/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xqm/myserver /home/xqm/myserver/base/tests /home/xqm/myserver/cmake-build-debug /home/xqm/myserver/cmake-build-debug/base/tests /home/xqm/myserver/cmake-build-debug/base/tests/CMakeFiles/Exception_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : base/tests/CMakeFiles/Exception_test.dir/depend

