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
include CMakeFiles/BTree_oko.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/BTree_oko.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BTree_oko.dir/flags.make

CMakeFiles/BTree_oko.dir/main.cpp.o: CMakeFiles/BTree_oko.dir/flags.make
CMakeFiles/BTree_oko.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dybacap13/BTree_oko/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BTree_oko.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BTree_oko.dir/main.cpp.o -c /home/dybacap13/BTree_oko/main.cpp

CMakeFiles/BTree_oko.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BTree_oko.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dybacap13/BTree_oko/main.cpp > CMakeFiles/BTree_oko.dir/main.cpp.i

CMakeFiles/BTree_oko.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BTree_oko.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dybacap13/BTree_oko/main.cpp -o CMakeFiles/BTree_oko.dir/main.cpp.s

# Object files for target BTree_oko
BTree_oko_OBJECTS = \
"CMakeFiles/BTree_oko.dir/main.cpp.o"

# External object files for target BTree_oko
BTree_oko_EXTERNAL_OBJECTS =

BTree_oko: CMakeFiles/BTree_oko.dir/main.cpp.o
BTree_oko: CMakeFiles/BTree_oko.dir/build.make
BTree_oko: /usr/local/lib/libbehaviortree_cpp.so
BTree_oko: CMakeFiles/BTree_oko.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dybacap13/BTree_oko/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable BTree_oko"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BTree_oko.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BTree_oko.dir/build: BTree_oko

.PHONY : CMakeFiles/BTree_oko.dir/build

CMakeFiles/BTree_oko.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BTree_oko.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BTree_oko.dir/clean

CMakeFiles/BTree_oko.dir/depend:
	cd /home/dybacap13/BTree_oko/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dybacap13/BTree_oko /home/dybacap13/BTree_oko /home/dybacap13/BTree_oko/build /home/dybacap13/BTree_oko/build /home/dybacap13/BTree_oko/build/CMakeFiles/BTree_oko.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BTree_oko.dir/depend

