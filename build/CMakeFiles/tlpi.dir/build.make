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
include CMakeFiles/tlpi.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tlpi.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tlpi.dir/flags.make

CMakeFiles/tlpi.dir/include/error_functions.c.o: CMakeFiles/tlpi.dir/flags.make
CMakeFiles/tlpi.dir/include/error_functions.c.o: ../include/error_functions.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leaf/cpp_work/tlpi-note/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/tlpi.dir/include/error_functions.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/tlpi.dir/include/error_functions.c.o   -c /home/leaf/cpp_work/tlpi-note/include/error_functions.c

CMakeFiles/tlpi.dir/include/error_functions.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tlpi.dir/include/error_functions.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/leaf/cpp_work/tlpi-note/include/error_functions.c > CMakeFiles/tlpi.dir/include/error_functions.c.i

CMakeFiles/tlpi.dir/include/error_functions.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tlpi.dir/include/error_functions.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/leaf/cpp_work/tlpi-note/include/error_functions.c -o CMakeFiles/tlpi.dir/include/error_functions.c.s

CMakeFiles/tlpi.dir/include/get_num.c.o: CMakeFiles/tlpi.dir/flags.make
CMakeFiles/tlpi.dir/include/get_num.c.o: ../include/get_num.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leaf/cpp_work/tlpi-note/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/tlpi.dir/include/get_num.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/tlpi.dir/include/get_num.c.o   -c /home/leaf/cpp_work/tlpi-note/include/get_num.c

CMakeFiles/tlpi.dir/include/get_num.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tlpi.dir/include/get_num.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/leaf/cpp_work/tlpi-note/include/get_num.c > CMakeFiles/tlpi.dir/include/get_num.c.i

CMakeFiles/tlpi.dir/include/get_num.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tlpi.dir/include/get_num.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/leaf/cpp_work/tlpi-note/include/get_num.c -o CMakeFiles/tlpi.dir/include/get_num.c.s

# Object files for target tlpi
tlpi_OBJECTS = \
"CMakeFiles/tlpi.dir/include/error_functions.c.o" \
"CMakeFiles/tlpi.dir/include/get_num.c.o"

# External object files for target tlpi
tlpi_EXTERNAL_OBJECTS =

../lib/libtlpi.a: CMakeFiles/tlpi.dir/include/error_functions.c.o
../lib/libtlpi.a: CMakeFiles/tlpi.dir/include/get_num.c.o
../lib/libtlpi.a: CMakeFiles/tlpi.dir/build.make
../lib/libtlpi.a: CMakeFiles/tlpi.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/leaf/cpp_work/tlpi-note/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C static library ../lib/libtlpi.a"
	$(CMAKE_COMMAND) -P CMakeFiles/tlpi.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tlpi.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tlpi.dir/build: ../lib/libtlpi.a

.PHONY : CMakeFiles/tlpi.dir/build

CMakeFiles/tlpi.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tlpi.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tlpi.dir/clean

CMakeFiles/tlpi.dir/depend:
	cd /home/leaf/cpp_work/tlpi-note/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/leaf/cpp_work/tlpi-note /home/leaf/cpp_work/tlpi-note /home/leaf/cpp_work/tlpi-note/build /home/leaf/cpp_work/tlpi-note/build /home/leaf/cpp_work/tlpi-note/build/CMakeFiles/tlpi.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tlpi.dir/depend

