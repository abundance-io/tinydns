# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_SOURCE_DIR = /home/abundance/random_projects/tinydns

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/abundance/random_projects/tinydns

# Include any dependencies generated for this target.
include CMakeFiles/tinydns.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/tinydns.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/tinydns.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tinydns.dir/flags.make

CMakeFiles/tinydns.dir/main.cpp.o: CMakeFiles/tinydns.dir/flags.make
CMakeFiles/tinydns.dir/main.cpp.o: main.cpp
CMakeFiles/tinydns.dir/main.cpp.o: CMakeFiles/tinydns.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/abundance/random_projects/tinydns/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tinydns.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tinydns.dir/main.cpp.o -MF CMakeFiles/tinydns.dir/main.cpp.o.d -o CMakeFiles/tinydns.dir/main.cpp.o -c /home/abundance/random_projects/tinydns/main.cpp

CMakeFiles/tinydns.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tinydns.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/abundance/random_projects/tinydns/main.cpp > CMakeFiles/tinydns.dir/main.cpp.i

CMakeFiles/tinydns.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tinydns.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/abundance/random_projects/tinydns/main.cpp -o CMakeFiles/tinydns.dir/main.cpp.s

# Object files for target tinydns
tinydns_OBJECTS = \
"CMakeFiles/tinydns.dir/main.cpp.o"

# External object files for target tinydns
tinydns_EXTERNAL_OBJECTS =

tinydns: CMakeFiles/tinydns.dir/main.cpp.o
tinydns: CMakeFiles/tinydns.dir/build.make
tinydns: CMakeFiles/tinydns.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/abundance/random_projects/tinydns/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tinydns"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tinydns.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tinydns.dir/build: tinydns
.PHONY : CMakeFiles/tinydns.dir/build

CMakeFiles/tinydns.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tinydns.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tinydns.dir/clean

CMakeFiles/tinydns.dir/depend:
	cd /home/abundance/random_projects/tinydns && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/abundance/random_projects/tinydns /home/abundance/random_projects/tinydns /home/abundance/random_projects/tinydns /home/abundance/random_projects/tinydns /home/abundance/random_projects/tinydns/CMakeFiles/tinydns.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/tinydns.dir/depend

