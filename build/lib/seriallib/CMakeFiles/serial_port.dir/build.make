# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_SOURCE_DIR = /home/airobot/Desktop/jetson_car

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/airobot/Desktop/jetson_car/build

# Include any dependencies generated for this target.
include lib/seriallib/CMakeFiles/serial_port.dir/depend.make

# Include the progress variables for this target.
include lib/seriallib/CMakeFiles/serial_port.dir/progress.make

# Include the compile flags for this target's objects.
include lib/seriallib/CMakeFiles/serial_port.dir/flags.make

lib/seriallib/CMakeFiles/serial_port.dir/serial_port.cpp.o: lib/seriallib/CMakeFiles/serial_port.dir/flags.make
lib/seriallib/CMakeFiles/serial_port.dir/serial_port.cpp.o: ../lib/seriallib/serial_port.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/airobot/Desktop/jetson_car/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/seriallib/CMakeFiles/serial_port.dir/serial_port.cpp.o"
	cd /home/airobot/Desktop/jetson_car/build/lib/seriallib && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/serial_port.dir/serial_port.cpp.o -c /home/airobot/Desktop/jetson_car/lib/seriallib/serial_port.cpp

lib/seriallib/CMakeFiles/serial_port.dir/serial_port.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serial_port.dir/serial_port.cpp.i"
	cd /home/airobot/Desktop/jetson_car/build/lib/seriallib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/airobot/Desktop/jetson_car/lib/seriallib/serial_port.cpp > CMakeFiles/serial_port.dir/serial_port.cpp.i

lib/seriallib/CMakeFiles/serial_port.dir/serial_port.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serial_port.dir/serial_port.cpp.s"
	cd /home/airobot/Desktop/jetson_car/build/lib/seriallib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/airobot/Desktop/jetson_car/lib/seriallib/serial_port.cpp -o CMakeFiles/serial_port.dir/serial_port.cpp.s

# Object files for target serial_port
serial_port_OBJECTS = \
"CMakeFiles/serial_port.dir/serial_port.cpp.o"

# External object files for target serial_port
serial_port_EXTERNAL_OBJECTS =

lib/seriallib/libserial_port.so: lib/seriallib/CMakeFiles/serial_port.dir/serial_port.cpp.o
lib/seriallib/libserial_port.so: lib/seriallib/CMakeFiles/serial_port.dir/build.make
lib/seriallib/libserial_port.so: lib/seriallib/CMakeFiles/serial_port.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/airobot/Desktop/jetson_car/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libserial_port.so"
	cd /home/airobot/Desktop/jetson_car/build/lib/seriallib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/serial_port.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/seriallib/CMakeFiles/serial_port.dir/build: lib/seriallib/libserial_port.so

.PHONY : lib/seriallib/CMakeFiles/serial_port.dir/build

lib/seriallib/CMakeFiles/serial_port.dir/clean:
	cd /home/airobot/Desktop/jetson_car/build/lib/seriallib && $(CMAKE_COMMAND) -P CMakeFiles/serial_port.dir/cmake_clean.cmake
.PHONY : lib/seriallib/CMakeFiles/serial_port.dir/clean

lib/seriallib/CMakeFiles/serial_port.dir/depend:
	cd /home/airobot/Desktop/jetson_car/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/airobot/Desktop/jetson_car /home/airobot/Desktop/jetson_car/lib/seriallib /home/airobot/Desktop/jetson_car/build /home/airobot/Desktop/jetson_car/build/lib/seriallib /home/airobot/Desktop/jetson_car/build/lib/seriallib/CMakeFiles/serial_port.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/seriallib/CMakeFiles/serial_port.dir/depend
