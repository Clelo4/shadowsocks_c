# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /opt/clion-2018.3.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2018.3.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/build

# Include any dependencies generated for this target.
include src/CMakeFiles/local.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/local.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/local.dir/flags.make

src/CMakeFiles/local.dir/local.c.o: src/CMakeFiles/local.dir/flags.make
src/CMakeFiles/local.dir/local.c.o: ../src/local.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/CMakeFiles/local.dir/local.c.o"
	cd /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/local.dir/local.c.o   -c /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/src/local.c

src/CMakeFiles/local.dir/local.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/local.dir/local.c.i"
	cd /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/src/local.c > CMakeFiles/local.dir/local.c.i

src/CMakeFiles/local.dir/local.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/local.dir/local.c.s"
	cd /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/src/local.c -o CMakeFiles/local.dir/local.c.s

src/CMakeFiles/local.dir/shell.c.o: src/CMakeFiles/local.dir/flags.make
src/CMakeFiles/local.dir/shell.c.o: ../src/shell.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object src/CMakeFiles/local.dir/shell.c.o"
	cd /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/local.dir/shell.c.o   -c /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/src/shell.c

src/CMakeFiles/local.dir/shell.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/local.dir/shell.c.i"
	cd /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/src/shell.c > CMakeFiles/local.dir/shell.c.i

src/CMakeFiles/local.dir/shell.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/local.dir/shell.c.s"
	cd /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/src/shell.c -o CMakeFiles/local.dir/shell.c.s

src/CMakeFiles/local.dir/eventloop.c.o: src/CMakeFiles/local.dir/flags.make
src/CMakeFiles/local.dir/eventloop.c.o: ../src/eventloop.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object src/CMakeFiles/local.dir/eventloop.c.o"
	cd /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/local.dir/eventloop.c.o   -c /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/src/eventloop.c

src/CMakeFiles/local.dir/eventloop.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/local.dir/eventloop.c.i"
	cd /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/src/eventloop.c > CMakeFiles/local.dir/eventloop.c.i

src/CMakeFiles/local.dir/eventloop.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/local.dir/eventloop.c.s"
	cd /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/src/eventloop.c -o CMakeFiles/local.dir/eventloop.c.s

src/CMakeFiles/local.dir/tcprelay.c.o: src/CMakeFiles/local.dir/flags.make
src/CMakeFiles/local.dir/tcprelay.c.o: ../src/tcprelay.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object src/CMakeFiles/local.dir/tcprelay.c.o"
	cd /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/local.dir/tcprelay.c.o   -c /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/src/tcprelay.c

src/CMakeFiles/local.dir/tcprelay.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/local.dir/tcprelay.c.i"
	cd /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/src/tcprelay.c > CMakeFiles/local.dir/tcprelay.c.i

src/CMakeFiles/local.dir/tcprelay.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/local.dir/tcprelay.c.s"
	cd /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/src/tcprelay.c -o CMakeFiles/local.dir/tcprelay.c.s

src/CMakeFiles/local.dir/udprelay.c.o: src/CMakeFiles/local.dir/flags.make
src/CMakeFiles/local.dir/udprelay.c.o: ../src/udprelay.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object src/CMakeFiles/local.dir/udprelay.c.o"
	cd /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/local.dir/udprelay.c.o   -c /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/src/udprelay.c

src/CMakeFiles/local.dir/udprelay.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/local.dir/udprelay.c.i"
	cd /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/src/udprelay.c > CMakeFiles/local.dir/udprelay.c.i

src/CMakeFiles/local.dir/udprelay.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/local.dir/udprelay.c.s"
	cd /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/src/udprelay.c -o CMakeFiles/local.dir/udprelay.c.s

src/CMakeFiles/local.dir/json/cJSON.c.o: src/CMakeFiles/local.dir/flags.make
src/CMakeFiles/local.dir/json/cJSON.c.o: ../src/json/cJSON.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object src/CMakeFiles/local.dir/json/cJSON.c.o"
	cd /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/local.dir/json/cJSON.c.o   -c /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/src/json/cJSON.c

src/CMakeFiles/local.dir/json/cJSON.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/local.dir/json/cJSON.c.i"
	cd /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/src/json/cJSON.c > CMakeFiles/local.dir/json/cJSON.c.i

src/CMakeFiles/local.dir/json/cJSON.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/local.dir/json/cJSON.c.s"
	cd /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/src/json/cJSON.c -o CMakeFiles/local.dir/json/cJSON.c.s

src/CMakeFiles/local.dir/encrypt.c.o: src/CMakeFiles/local.dir/flags.make
src/CMakeFiles/local.dir/encrypt.c.o: ../src/encrypt.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object src/CMakeFiles/local.dir/encrypt.c.o"
	cd /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/local.dir/encrypt.c.o   -c /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/src/encrypt.c

src/CMakeFiles/local.dir/encrypt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/local.dir/encrypt.c.i"
	cd /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/src/encrypt.c > CMakeFiles/local.dir/encrypt.c.i

src/CMakeFiles/local.dir/encrypt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/local.dir/encrypt.c.s"
	cd /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/src/encrypt.c -o CMakeFiles/local.dir/encrypt.c.s

src/CMakeFiles/local.dir/daemon.c.o: src/CMakeFiles/local.dir/flags.make
src/CMakeFiles/local.dir/daemon.c.o: ../src/daemon.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object src/CMakeFiles/local.dir/daemon.c.o"
	cd /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/local.dir/daemon.c.o   -c /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/src/daemon.c

src/CMakeFiles/local.dir/daemon.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/local.dir/daemon.c.i"
	cd /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/src/daemon.c > CMakeFiles/local.dir/daemon.c.i

src/CMakeFiles/local.dir/daemon.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/local.dir/daemon.c.s"
	cd /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/src/daemon.c -o CMakeFiles/local.dir/daemon.c.s

src/CMakeFiles/local.dir/asyncdns.c.o: src/CMakeFiles/local.dir/flags.make
src/CMakeFiles/local.dir/asyncdns.c.o: ../src/asyncdns.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object src/CMakeFiles/local.dir/asyncdns.c.o"
	cd /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/local.dir/asyncdns.c.o   -c /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/src/asyncdns.c

src/CMakeFiles/local.dir/asyncdns.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/local.dir/asyncdns.c.i"
	cd /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/src/asyncdns.c > CMakeFiles/local.dir/asyncdns.c.i

src/CMakeFiles/local.dir/asyncdns.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/local.dir/asyncdns.c.s"
	cd /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/src/asyncdns.c -o CMakeFiles/local.dir/asyncdns.c.s

src/CMakeFiles/local.dir/common.c.o: src/CMakeFiles/local.dir/flags.make
src/CMakeFiles/local.dir/common.c.o: ../src/common.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object src/CMakeFiles/local.dir/common.c.o"
	cd /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/local.dir/common.c.o   -c /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/src/common.c

src/CMakeFiles/local.dir/common.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/local.dir/common.c.i"
	cd /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/src/common.c > CMakeFiles/local.dir/common.c.i

src/CMakeFiles/local.dir/common.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/local.dir/common.c.s"
	cd /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/src/common.c -o CMakeFiles/local.dir/common.c.s

src/CMakeFiles/local.dir/log.c.o: src/CMakeFiles/local.dir/flags.make
src/CMakeFiles/local.dir/log.c.o: ../src/log.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object src/CMakeFiles/local.dir/log.c.o"
	cd /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/local.dir/log.c.o   -c /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/src/log.c

src/CMakeFiles/local.dir/log.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/local.dir/log.c.i"
	cd /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/src/log.c > CMakeFiles/local.dir/log.c.i

src/CMakeFiles/local.dir/log.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/local.dir/log.c.s"
	cd /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/src/log.c -o CMakeFiles/local.dir/log.c.s

src/CMakeFiles/local.dir/utils/fd_map.c.o: src/CMakeFiles/local.dir/flags.make
src/CMakeFiles/local.dir/utils/fd_map.c.o: ../src/utils/fd_map.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object src/CMakeFiles/local.dir/utils/fd_map.c.o"
	cd /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/local.dir/utils/fd_map.c.o   -c /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/src/utils/fd_map.c

src/CMakeFiles/local.dir/utils/fd_map.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/local.dir/utils/fd_map.c.i"
	cd /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/src/utils/fd_map.c > CMakeFiles/local.dir/utils/fd_map.c.i

src/CMakeFiles/local.dir/utils/fd_map.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/local.dir/utils/fd_map.c.s"
	cd /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/src/utils/fd_map.c -o CMakeFiles/local.dir/utils/fd_map.c.s

src/CMakeFiles/local.dir/utils/lru_cache.c.o: src/CMakeFiles/local.dir/flags.make
src/CMakeFiles/local.dir/utils/lru_cache.c.o: ../src/utils/lru_cache.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building C object src/CMakeFiles/local.dir/utils/lru_cache.c.o"
	cd /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/local.dir/utils/lru_cache.c.o   -c /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/src/utils/lru_cache.c

src/CMakeFiles/local.dir/utils/lru_cache.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/local.dir/utils/lru_cache.c.i"
	cd /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/src/utils/lru_cache.c > CMakeFiles/local.dir/utils/lru_cache.c.i

src/CMakeFiles/local.dir/utils/lru_cache.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/local.dir/utils/lru_cache.c.s"
	cd /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/src/utils/lru_cache.c -o CMakeFiles/local.dir/utils/lru_cache.c.s

# Object files for target local
local_OBJECTS = \
"CMakeFiles/local.dir/local.c.o" \
"CMakeFiles/local.dir/shell.c.o" \
"CMakeFiles/local.dir/eventloop.c.o" \
"CMakeFiles/local.dir/tcprelay.c.o" \
"CMakeFiles/local.dir/udprelay.c.o" \
"CMakeFiles/local.dir/json/cJSON.c.o" \
"CMakeFiles/local.dir/encrypt.c.o" \
"CMakeFiles/local.dir/daemon.c.o" \
"CMakeFiles/local.dir/asyncdns.c.o" \
"CMakeFiles/local.dir/common.c.o" \
"CMakeFiles/local.dir/log.c.o" \
"CMakeFiles/local.dir/utils/fd_map.c.o" \
"CMakeFiles/local.dir/utils/lru_cache.c.o"

# External object files for target local
local_EXTERNAL_OBJECTS =

bin/local: src/CMakeFiles/local.dir/local.c.o
bin/local: src/CMakeFiles/local.dir/shell.c.o
bin/local: src/CMakeFiles/local.dir/eventloop.c.o
bin/local: src/CMakeFiles/local.dir/tcprelay.c.o
bin/local: src/CMakeFiles/local.dir/udprelay.c.o
bin/local: src/CMakeFiles/local.dir/json/cJSON.c.o
bin/local: src/CMakeFiles/local.dir/encrypt.c.o
bin/local: src/CMakeFiles/local.dir/daemon.c.o
bin/local: src/CMakeFiles/local.dir/asyncdns.c.o
bin/local: src/CMakeFiles/local.dir/common.c.o
bin/local: src/CMakeFiles/local.dir/log.c.o
bin/local: src/CMakeFiles/local.dir/utils/fd_map.c.o
bin/local: src/CMakeFiles/local.dir/utils/lru_cache.c.o
bin/local: src/CMakeFiles/local.dir/build.make
bin/local: src/CMakeFiles/local.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Linking C executable ../bin/local"
	cd /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/local.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/local.dir/build: bin/local

.PHONY : src/CMakeFiles/local.dir/build

src/CMakeFiles/local.dir/clean:
	cd /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/build/src && $(CMAKE_COMMAND) -P CMakeFiles/local.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/local.dir/clean

src/CMakeFiles/local.dir/depend:
	cd /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/src /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/build /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/build/src /media/jack/176a013f-761b-4d68-9653-03ef516584ed/home/jack/CLionProjects/shadowsocks_c/build/src/CMakeFiles/local.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/local.dir/depend

