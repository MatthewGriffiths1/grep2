# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/matt/dev/HelloWorld

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/matt/dev/HelloWorld

# Include any dependencies generated for this target.
include CMakeFiles/HellowWorld.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/HellowWorld.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/HellowWorld.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HellowWorld.dir/flags.make

CMakeFiles/HellowWorld.dir/src/Main.cpp.o: CMakeFiles/HellowWorld.dir/flags.make
CMakeFiles/HellowWorld.dir/src/Main.cpp.o: src/Main.cpp
CMakeFiles/HellowWorld.dir/src/Main.cpp.o: CMakeFiles/HellowWorld.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/matt/dev/HelloWorld/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/HellowWorld.dir/src/Main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/HellowWorld.dir/src/Main.cpp.o -MF CMakeFiles/HellowWorld.dir/src/Main.cpp.o.d -o CMakeFiles/HellowWorld.dir/src/Main.cpp.o -c /home/matt/dev/HelloWorld/src/Main.cpp

CMakeFiles/HellowWorld.dir/src/Main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/HellowWorld.dir/src/Main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/matt/dev/HelloWorld/src/Main.cpp > CMakeFiles/HellowWorld.dir/src/Main.cpp.i

CMakeFiles/HellowWorld.dir/src/Main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/HellowWorld.dir/src/Main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/matt/dev/HelloWorld/src/Main.cpp -o CMakeFiles/HellowWorld.dir/src/Main.cpp.s

# Object files for target HellowWorld
HellowWorld_OBJECTS = \
"CMakeFiles/HellowWorld.dir/src/Main.cpp.o"

# External object files for target HellowWorld
HellowWorld_EXTERNAL_OBJECTS =

HellowWorld: CMakeFiles/HellowWorld.dir/src/Main.cpp.o
HellowWorld: CMakeFiles/HellowWorld.dir/build.make
HellowWorld: CMakeFiles/HellowWorld.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/matt/dev/HelloWorld/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable HellowWorld"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/HellowWorld.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HellowWorld.dir/build: HellowWorld
.PHONY : CMakeFiles/HellowWorld.dir/build

CMakeFiles/HellowWorld.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/HellowWorld.dir/cmake_clean.cmake
.PHONY : CMakeFiles/HellowWorld.dir/clean

CMakeFiles/HellowWorld.dir/depend:
	cd /home/matt/dev/HelloWorld && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/matt/dev/HelloWorld /home/matt/dev/HelloWorld /home/matt/dev/HelloWorld /home/matt/dev/HelloWorld /home/matt/dev/HelloWorld/CMakeFiles/HellowWorld.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/HellowWorld.dir/depend

