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
CMAKE_SOURCE_DIR = /home/leaf/cpp_work/tlpi-note

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/leaf/cpp_work/tlpi-note/build

# Include any dependencies generated for this target.
include CMakeFiles/display_env.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/display_env.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/display_env.dir/flags.make

CMakeFiles/display_env.dir/src/ch06/display_env.c.o: CMakeFiles/display_env.dir/flags.make
CMakeFiles/display_env.dir/src/ch06/display_env.c.o: ../src/ch06/display_env.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leaf/cpp_work/tlpi-note/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/display_env.dir/src/ch06/display_env.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/display_env.dir/src/ch06/display_env.c.o   -c /home/leaf/cpp_work/tlpi-note/src/ch06/display_env.c

CMakeFiles/display_env.dir/src/ch06/display_env.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/display_env.dir/src/ch06/display_env.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/leaf/cpp_work/tlpi-note/src/ch06/display_env.c > CMakeFiles/display_env.dir/src/ch06/display_env.c.i

CMakeFiles/display_env.dir/src/ch06/display_env.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/display_env.dir/src/ch06/display_env.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/leaf/cpp_work/tlpi-note/src/ch06/display_env.c -o CMakeFiles/display_env.dir/src/ch06/display_env.c.s

# Object files for target display_env
display_env_OBJECTS = \
"CMakeFiles/display_env.dir/src/ch06/display_env.c.o"

# External object files for target display_env
display_env_EXTERNAL_OBJECTS =

../bin/display_env: CMakeFiles/display_env.dir/src/ch06/display_env.c.o
../bin/display_env: CMakeFiles/display_env.dir/build.make
../bin/display_env: ../lib/libtlpi.a
../bin/display_env: CMakeFiles/display_env.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/leaf/cpp_work/tlpi-note/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ../bin/display_env"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/display_env.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/display_env.dir/build: ../bin/display_env

.PHONY : CMakeFiles/display_env.dir/build

CMakeFiles/display_env.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/display_env.dir/cmake_clean.cmake
.PHONY : CMakeFiles/display_env.dir/clean

CMakeFiles/display_env.dir/depend:
	cd /home/leaf/cpp_work/tlpi-note/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/leaf/cpp_work/tlpi-note /home/leaf/cpp_work/tlpi-note /home/leaf/cpp_work/tlpi-note/build /home/leaf/cpp_work/tlpi-note/build /home/leaf/cpp_work/tlpi-note/build/CMakeFiles/display_env.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/display_env.dir/depend
