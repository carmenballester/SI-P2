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
include examples/iris_plant/CMakeFiles/iris_plant.dir/depend.make

# Include the progress variables for this target.
include examples/iris_plant/CMakeFiles/iris_plant.dir/progress.make

# Include the compile flags for this target's objects.
include examples/iris_plant/CMakeFiles/iris_plant.dir/flags.make

examples/iris_plant/CMakeFiles/iris_plant.dir/main.cpp.o: examples/iris_plant/CMakeFiles/iris_plant.dir/flags.make
examples/iris_plant/CMakeFiles/iris_plant.dir/main.cpp.o: examples/iris_plant/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/carmenballester/Escritorio/Practica2/OpenNN/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/iris_plant/CMakeFiles/iris_plant.dir/main.cpp.o"
	cd /home/carmenballester/Escritorio/Practica2/OpenNN/examples/iris_plant && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/iris_plant.dir/main.cpp.o -c /home/carmenballester/Escritorio/Practica2/OpenNN/examples/iris_plant/main.cpp

examples/iris_plant/CMakeFiles/iris_plant.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/iris_plant.dir/main.cpp.i"
	cd /home/carmenballester/Escritorio/Practica2/OpenNN/examples/iris_plant && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/carmenballester/Escritorio/Practica2/OpenNN/examples/iris_plant/main.cpp > CMakeFiles/iris_plant.dir/main.cpp.i

examples/iris_plant/CMakeFiles/iris_plant.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/iris_plant.dir/main.cpp.s"
	cd /home/carmenballester/Escritorio/Practica2/OpenNN/examples/iris_plant && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/carmenballester/Escritorio/Practica2/OpenNN/examples/iris_plant/main.cpp -o CMakeFiles/iris_plant.dir/main.cpp.s

examples/iris_plant/CMakeFiles/iris_plant.dir/main.cpp.o.requires:

.PHONY : examples/iris_plant/CMakeFiles/iris_plant.dir/main.cpp.o.requires

examples/iris_plant/CMakeFiles/iris_plant.dir/main.cpp.o.provides: examples/iris_plant/CMakeFiles/iris_plant.dir/main.cpp.o.requires
	$(MAKE) -f examples/iris_plant/CMakeFiles/iris_plant.dir/build.make examples/iris_plant/CMakeFiles/iris_plant.dir/main.cpp.o.provides.build
.PHONY : examples/iris_plant/CMakeFiles/iris_plant.dir/main.cpp.o.provides

examples/iris_plant/CMakeFiles/iris_plant.dir/main.cpp.o.provides.build: examples/iris_plant/CMakeFiles/iris_plant.dir/main.cpp.o


# Object files for target iris_plant
iris_plant_OBJECTS = \
"CMakeFiles/iris_plant.dir/main.cpp.o"

# External object files for target iris_plant
iris_plant_EXTERNAL_OBJECTS =

examples/iris_plant/iris_plant: examples/iris_plant/CMakeFiles/iris_plant.dir/main.cpp.o
examples/iris_plant/iris_plant: examples/iris_plant/CMakeFiles/iris_plant.dir/build.make
examples/iris_plant/iris_plant: opennn/libopennn.a
examples/iris_plant/iris_plant: tinyxml2/libtinyxml2.a
examples/iris_plant/iris_plant: examples/iris_plant/CMakeFiles/iris_plant.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/carmenballester/Escritorio/Practica2/OpenNN/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable iris_plant"
	cd /home/carmenballester/Escritorio/Practica2/OpenNN/examples/iris_plant && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/iris_plant.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/iris_plant/CMakeFiles/iris_plant.dir/build: examples/iris_plant/iris_plant

.PHONY : examples/iris_plant/CMakeFiles/iris_plant.dir/build

examples/iris_plant/CMakeFiles/iris_plant.dir/requires: examples/iris_plant/CMakeFiles/iris_plant.dir/main.cpp.o.requires

.PHONY : examples/iris_plant/CMakeFiles/iris_plant.dir/requires

examples/iris_plant/CMakeFiles/iris_plant.dir/clean:
	cd /home/carmenballester/Escritorio/Practica2/OpenNN/examples/iris_plant && $(CMAKE_COMMAND) -P CMakeFiles/iris_plant.dir/cmake_clean.cmake
.PHONY : examples/iris_plant/CMakeFiles/iris_plant.dir/clean

examples/iris_plant/CMakeFiles/iris_plant.dir/depend:
	cd /home/carmenballester/Escritorio/Practica2/OpenNN && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/carmenballester/Escritorio/Practica2/OpenNN /home/carmenballester/Escritorio/Practica2/OpenNN/examples/iris_plant /home/carmenballester/Escritorio/Practica2/OpenNN /home/carmenballester/Escritorio/Practica2/OpenNN/examples/iris_plant /home/carmenballester/Escritorio/Practica2/OpenNN/examples/iris_plant/CMakeFiles/iris_plant.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/iris_plant/CMakeFiles/iris_plant.dir/depend

