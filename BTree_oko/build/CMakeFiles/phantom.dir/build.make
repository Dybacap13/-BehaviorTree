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
CMAKE_SOURCE_DIR = /home/dybacap13/BTree_oko

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dybacap13/BTree_oko/build

# Include any dependencies generated for this target.
include CMakeFiles/phantom.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/phantom.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/phantom.dir/flags.make

CMakeFiles/phantom.dir/src/phantom.cpp.o: CMakeFiles/phantom.dir/flags.make
CMakeFiles/phantom.dir/src/phantom.cpp.o: ../src/phantom.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dybacap13/BTree_oko/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/phantom.dir/src/phantom.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/phantom.dir/src/phantom.cpp.o -c /home/dybacap13/BTree_oko/src/phantom.cpp

CMakeFiles/phantom.dir/src/phantom.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/phantom.dir/src/phantom.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dybacap13/BTree_oko/src/phantom.cpp > CMakeFiles/phantom.dir/src/phantom.cpp.i

CMakeFiles/phantom.dir/src/phantom.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/phantom.dir/src/phantom.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dybacap13/BTree_oko/src/phantom.cpp -o CMakeFiles/phantom.dir/src/phantom.cpp.s

# Object files for target phantom
phantom_OBJECTS = \
"CMakeFiles/phantom.dir/src/phantom.cpp.o"

# External object files for target phantom
phantom_EXTERNAL_OBJECTS =

phantom: CMakeFiles/phantom.dir/src/phantom.cpp.o
phantom: CMakeFiles/phantom.dir/build.make
phantom: /usr/local/lib/libbehaviortree_cpp.so
phantom: CMakeFiles/phantom.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dybacap13/BTree_oko/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable phantom"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/phantom.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/phantom.dir/build: phantom

.PHONY : CMakeFiles/phantom.dir/build

CMakeFiles/phantom.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/phantom.dir/cmake_clean.cmake
.PHONY : CMakeFiles/phantom.dir/clean

CMakeFiles/phantom.dir/depend:
	cd /home/dybacap13/BTree_oko/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dybacap13/BTree_oko /home/dybacap13/BTree_oko /home/dybacap13/BTree_oko/build /home/dybacap13/BTree_oko/build /home/dybacap13/BTree_oko/build/CMakeFiles/phantom.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/phantom.dir/depend

