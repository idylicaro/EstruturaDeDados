# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Alucard\CLionProjects\PilhaArranjo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Alucard\CLionProjects\PilhaArranjo\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/PilhaArranjo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PilhaArranjo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PilhaArranjo.dir/flags.make

CMakeFiles/PilhaArranjo.dir/main.cpp.obj: CMakeFiles/PilhaArranjo.dir/flags.make
CMakeFiles/PilhaArranjo.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Alucard\CLionProjects\PilhaArranjo\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PilhaArranjo.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\PilhaArranjo.dir\main.cpp.obj -c C:\Users\Alucard\CLionProjects\PilhaArranjo\main.cpp

CMakeFiles/PilhaArranjo.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PilhaArranjo.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Alucard\CLionProjects\PilhaArranjo\main.cpp > CMakeFiles\PilhaArranjo.dir\main.cpp.i

CMakeFiles/PilhaArranjo.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PilhaArranjo.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Alucard\CLionProjects\PilhaArranjo\main.cpp -o CMakeFiles\PilhaArranjo.dir\main.cpp.s

# Object files for target PilhaArranjo
PilhaArranjo_OBJECTS = \
"CMakeFiles/PilhaArranjo.dir/main.cpp.obj"

# External object files for target PilhaArranjo
PilhaArranjo_EXTERNAL_OBJECTS =

PilhaArranjo.exe: CMakeFiles/PilhaArranjo.dir/main.cpp.obj
PilhaArranjo.exe: CMakeFiles/PilhaArranjo.dir/build.make
PilhaArranjo.exe: CMakeFiles/PilhaArranjo.dir/linklibs.rsp
PilhaArranjo.exe: CMakeFiles/PilhaArranjo.dir/objects1.rsp
PilhaArranjo.exe: CMakeFiles/PilhaArranjo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Alucard\CLionProjects\PilhaArranjo\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable PilhaArranjo.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\PilhaArranjo.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PilhaArranjo.dir/build: PilhaArranjo.exe

.PHONY : CMakeFiles/PilhaArranjo.dir/build

CMakeFiles/PilhaArranjo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\PilhaArranjo.dir\cmake_clean.cmake
.PHONY : CMakeFiles/PilhaArranjo.dir/clean

CMakeFiles/PilhaArranjo.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Alucard\CLionProjects\PilhaArranjo C:\Users\Alucard\CLionProjects\PilhaArranjo C:\Users\Alucard\CLionProjects\PilhaArranjo\cmake-build-debug C:\Users\Alucard\CLionProjects\PilhaArranjo\cmake-build-debug C:\Users\Alucard\CLionProjects\PilhaArranjo\cmake-build-debug\CMakeFiles\PilhaArranjo.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PilhaArranjo.dir/depend
