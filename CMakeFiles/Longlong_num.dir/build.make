# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/andrewche/projects/big_nums

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/andrewche/projects/big_nums

# Include any dependencies generated for this target.
include CMakeFiles/Longlong_num.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Longlong_num.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Longlong_num.dir/flags.make

CMakeFiles/Longlong_num.dir/main.c.o: CMakeFiles/Longlong_num.dir/flags.make
CMakeFiles/Longlong_num.dir/main.c.o: main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andrewche/projects/big_nums/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Longlong_num.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Longlong_num.dir/main.c.o   -c /home/andrewche/projects/big_nums/main.c

CMakeFiles/Longlong_num.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Longlong_num.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/andrewche/projects/big_nums/main.c > CMakeFiles/Longlong_num.dir/main.c.i

CMakeFiles/Longlong_num.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Longlong_num.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/andrewche/projects/big_nums/main.c -o CMakeFiles/Longlong_num.dir/main.c.s

CMakeFiles/Longlong_num.dir/main.c.o.requires:

.PHONY : CMakeFiles/Longlong_num.dir/main.c.o.requires

CMakeFiles/Longlong_num.dir/main.c.o.provides: CMakeFiles/Longlong_num.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/Longlong_num.dir/build.make CMakeFiles/Longlong_num.dir/main.c.o.provides.build
.PHONY : CMakeFiles/Longlong_num.dir/main.c.o.provides

CMakeFiles/Longlong_num.dir/main.c.o.provides.build: CMakeFiles/Longlong_num.dir/main.c.o


CMakeFiles/Longlong_num.dir/bn_matrenok.c.o: CMakeFiles/Longlong_num.dir/flags.make
CMakeFiles/Longlong_num.dir/bn_matrenok.c.o: bn_matrenok.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andrewche/projects/big_nums/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Longlong_num.dir/bn_matrenok.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Longlong_num.dir/bn_matrenok.c.o   -c /home/andrewche/projects/big_nums/bn_matrenok.c

CMakeFiles/Longlong_num.dir/bn_matrenok.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Longlong_num.dir/bn_matrenok.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/andrewche/projects/big_nums/bn_matrenok.c > CMakeFiles/Longlong_num.dir/bn_matrenok.c.i

CMakeFiles/Longlong_num.dir/bn_matrenok.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Longlong_num.dir/bn_matrenok.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/andrewche/projects/big_nums/bn_matrenok.c -o CMakeFiles/Longlong_num.dir/bn_matrenok.c.s

CMakeFiles/Longlong_num.dir/bn_matrenok.c.o.requires:

.PHONY : CMakeFiles/Longlong_num.dir/bn_matrenok.c.o.requires

CMakeFiles/Longlong_num.dir/bn_matrenok.c.o.provides: CMakeFiles/Longlong_num.dir/bn_matrenok.c.o.requires
	$(MAKE) -f CMakeFiles/Longlong_num.dir/build.make CMakeFiles/Longlong_num.dir/bn_matrenok.c.o.provides.build
.PHONY : CMakeFiles/Longlong_num.dir/bn_matrenok.c.o.provides

CMakeFiles/Longlong_num.dir/bn_matrenok.c.o.provides.build: CMakeFiles/Longlong_num.dir/bn_matrenok.c.o


# Object files for target Longlong_num
Longlong_num_OBJECTS = \
"CMakeFiles/Longlong_num.dir/main.c.o" \
"CMakeFiles/Longlong_num.dir/bn_matrenok.c.o"

# External object files for target Longlong_num
Longlong_num_EXTERNAL_OBJECTS =

Longlong_num: CMakeFiles/Longlong_num.dir/main.c.o
Longlong_num: CMakeFiles/Longlong_num.dir/bn_matrenok.c.o
Longlong_num: CMakeFiles/Longlong_num.dir/build.make
Longlong_num: CMakeFiles/Longlong_num.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/andrewche/projects/big_nums/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable Longlong_num"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Longlong_num.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Longlong_num.dir/build: Longlong_num

.PHONY : CMakeFiles/Longlong_num.dir/build

CMakeFiles/Longlong_num.dir/requires: CMakeFiles/Longlong_num.dir/main.c.o.requires
CMakeFiles/Longlong_num.dir/requires: CMakeFiles/Longlong_num.dir/bn_matrenok.c.o.requires

.PHONY : CMakeFiles/Longlong_num.dir/requires

CMakeFiles/Longlong_num.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Longlong_num.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Longlong_num.dir/clean

CMakeFiles/Longlong_num.dir/depend:
	cd /home/andrewche/projects/big_nums && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/andrewche/projects/big_nums /home/andrewche/projects/big_nums /home/andrewche/projects/big_nums /home/andrewche/projects/big_nums /home/andrewche/projects/big_nums/CMakeFiles/Longlong_num.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Longlong_num.dir/depend

