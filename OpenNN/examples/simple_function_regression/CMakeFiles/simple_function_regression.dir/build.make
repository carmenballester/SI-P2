# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/carmenballester/Escritorio/Practica2/OpenNN

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/carmenballester/Escritorio/Practica2/OpenNN

# Include any dependencies generated for this target.
include examples/simple_function_regression/CMakeFiles/simple_function_regression.dir/depend.make

# Include the progress variables for this target.
include examples/simple_function_regression/CMakeFiles/simple_function_regression.dir/progress.make

# Include the compile flags for this target's objects.
include examples/simple_function_regression/CMakeFiles/simple_function_regression.dir/flags.make

examples/simple_function_regression/CMakeFiles/simple_function_regression.dir/main.cpp.o: examples/simple_function_regression/CMakeFiles/simple_function_regression.dir/flags.make
examples/simple_function_regression/CMakeFiles/simple_function_regression.dir/main.cpp.o: examples/simple_function_regression/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/carmenballester/Escritorio/Practica2/OpenNN/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/simple_function_regression/CMakeFiles/simple_function_regression.dir/main.cpp.o"
	cd /home/carmenballester/Escritorio/Practica2/OpenNN/examples/simple_function_regression && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/simple_function_regression.dir/main.cpp.o -c /home/carmenballester/Escritorio/Practica2/OpenNN/examples/simple_function_regression/main.cpp

examples/simple_function_regression/CMakeFiles/simple_function_regression.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simple_function_regression.dir/main.cpp.i"
	cd /home/carmenballester/Escritorio/Practica2/OpenNN/examples/simple_function_regression && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/carmenballester/Escritorio/Practica2/OpenNN/examples/simple_function_regression/main.cpp > CMakeFiles/simple_function_regression.dir/main.cpp.i

examples/simple_function_regression/CMakeFiles/simple_function_regression.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simple_function_regression.dir/main.cpp.s"
	cd /home/carmenballester/Escritorio/Practica2/OpenNN/examples/simple_function_regression && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/carmenballester/Escritorio/Practica2/OpenNN/examples/simple_function_regression/main.cpp -o CMakeFiles/simple_function_regression.dir/main.cpp.s

examples/simple_function_regression/CMakeFiles/simple_function_regression.dir/main.cpp.o.requires:

.PHONY : examples/simple_function_regression/CMakeFiles/simple_function_regression.dir/main.cpp.o.requires

examples/simple_function_regression/CMakeFiles/simple_function_regression.dir/main.cpp.o.provides: examples/simple_function_regression/CMakeFiles/simple_function_regression.dir/main.cpp.o.requires
	$(MAKE) -f examples/simple_function_regression/CMakeFiles/simple_function_regression.dir/build.make examples/simple_function_regression/CMakeFiles/simple_function_regression.dir/main.cpp.o.provides.build
.PHONY : examples/simple_function_regression/CMakeFiles/simple_function_regression.dir/main.cpp.o.provides

examples/simple_function_regression/CMakeFiles/simple_function_regression.dir/main.cpp.o.provides.build: examples/simple_function_regression/CMakeFiles/simple_function_regression.dir/main.cpp.o


# Object files for target simple_function_regression
simple_function_regression_OBJECTS = \
"CMakeFiles/simple_function_regression.dir/main.cpp.o"

# External object files for target simple_function_regression
simple_function_regression_EXTERNAL_OBJECTS =

examples/simple_function_regression/simple_function_regression: examples/simple_function_regression/CMakeFiles/simple_function_regression.dir/main.cpp.o
examples/simple_function_regression/simple_function_regression: examples/simple_function_regression/CMakeFiles/simple_function_regression.dir/build.make
examples/simple_function_regression/simple_function_regression: opennn/libopennn.a
examples/simple_function_regression/simple_function_regression: tinyxml2/libtinyxml2.a
examples/simple_function_regression/simple_function_regression: examples/simple_function_regression/CMakeFiles/simple_function_regression.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/carmenballester/Escritorio/Practica2/OpenNN/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable simple_function_regression"
	cd /home/carmenballester/Escritorio/Practica2/OpenNN/examples/simple_function_regression && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/simple_function_regression.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/simple_function_regression/CMakeFiles/simple_function_regression.dir/build: examples/simple_function_regression/simple_function_regression

.PHONY : examples/simple_function_regression/CMakeFiles/simple_function_regression.dir/build

examples/simple_function_regression/CMakeFiles/simple_function_regression.dir/requires: examples/simple_function_regression/CMakeFiles/simple_function_regression.dir/main.cpp.o.requires

.PHONY : examples/simple_function_regression/CMakeFiles/simple_function_regression.dir/requires

examples/simple_function_regression/CMakeFiles/simple_function_regression.dir/clean:
	cd /home/carmenballester/Escritorio/Practica2/OpenNN/examples/simple_function_regression && $(CMAKE_COMMAND) -P CMakeFiles/simple_function_regression.dir/cmake_clean.cmake
.PHONY : examples/simple_function_regression/CMakeFiles/simple_function_regression.dir/clean

examples/simple_function_regression/CMakeFiles/simple_function_regression.dir/depend:
	cd /home/carmenballester/Escritorio/Practica2/OpenNN && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/carmenballester/Escritorio/Practica2/OpenNN /home/carmenballester/Escritorio/Practica2/OpenNN/examples/simple_function_regression /home/carmenballester/Escritorio/Practica2/OpenNN /home/carmenballester/Escritorio/Practica2/OpenNN/examples/simple_function_regression /home/carmenballester/Escritorio/Practica2/OpenNN/examples/simple_function_regression/CMakeFiles/simple_function_regression.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/simple_function_regression/CMakeFiles/simple_function_regression.dir/depend

