# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /snap/clion/164/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/164/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/n4ssser/Image-Recovery/Image Recovery"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/n4ssser/Image-Recovery/Image Recovery/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Image_Recovery.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Image_Recovery.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Image_Recovery.dir/flags.make

CMakeFiles/Image_Recovery.dir/main.cpp.o: CMakeFiles/Image_Recovery.dir/flags.make
CMakeFiles/Image_Recovery.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/n4ssser/Image-Recovery/Image Recovery/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Image_Recovery.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Image_Recovery.dir/main.cpp.o -c "/home/n4ssser/Image-Recovery/Image Recovery/main.cpp"

CMakeFiles/Image_Recovery.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Image_Recovery.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/n4ssser/Image-Recovery/Image Recovery/main.cpp" > CMakeFiles/Image_Recovery.dir/main.cpp.i

CMakeFiles/Image_Recovery.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Image_Recovery.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/n4ssser/Image-Recovery/Image Recovery/main.cpp" -o CMakeFiles/Image_Recovery.dir/main.cpp.s

CMakeFiles/Image_Recovery.dir/Gen.cpp.o: CMakeFiles/Image_Recovery.dir/flags.make
CMakeFiles/Image_Recovery.dir/Gen.cpp.o: ../Gen.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/n4ssser/Image-Recovery/Image Recovery/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Image_Recovery.dir/Gen.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Image_Recovery.dir/Gen.cpp.o -c "/home/n4ssser/Image-Recovery/Image Recovery/Gen.cpp"

CMakeFiles/Image_Recovery.dir/Gen.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Image_Recovery.dir/Gen.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/n4ssser/Image-Recovery/Image Recovery/Gen.cpp" > CMakeFiles/Image_Recovery.dir/Gen.cpp.i

CMakeFiles/Image_Recovery.dir/Gen.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Image_Recovery.dir/Gen.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/n4ssser/Image-Recovery/Image Recovery/Gen.cpp" -o CMakeFiles/Image_Recovery.dir/Gen.cpp.s

CMakeFiles/Image_Recovery.dir/Solution.cpp.o: CMakeFiles/Image_Recovery.dir/flags.make
CMakeFiles/Image_Recovery.dir/Solution.cpp.o: ../Solution.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/n4ssser/Image-Recovery/Image Recovery/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Image_Recovery.dir/Solution.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Image_Recovery.dir/Solution.cpp.o -c "/home/n4ssser/Image-Recovery/Image Recovery/Solution.cpp"

CMakeFiles/Image_Recovery.dir/Solution.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Image_Recovery.dir/Solution.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/n4ssser/Image-Recovery/Image Recovery/Solution.cpp" > CMakeFiles/Image_Recovery.dir/Solution.cpp.i

CMakeFiles/Image_Recovery.dir/Solution.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Image_Recovery.dir/Solution.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/n4ssser/Image-Recovery/Image Recovery/Solution.cpp" -o CMakeFiles/Image_Recovery.dir/Solution.cpp.s

# Object files for target Image_Recovery
Image_Recovery_OBJECTS = \
"CMakeFiles/Image_Recovery.dir/main.cpp.o" \
"CMakeFiles/Image_Recovery.dir/Gen.cpp.o" \
"CMakeFiles/Image_Recovery.dir/Solution.cpp.o"

# External object files for target Image_Recovery
Image_Recovery_EXTERNAL_OBJECTS =

Image_Recovery: CMakeFiles/Image_Recovery.dir/main.cpp.o
Image_Recovery: CMakeFiles/Image_Recovery.dir/Gen.cpp.o
Image_Recovery: CMakeFiles/Image_Recovery.dir/Solution.cpp.o
Image_Recovery: CMakeFiles/Image_Recovery.dir/build.make
Image_Recovery: CMakeFiles/Image_Recovery.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/n4ssser/Image-Recovery/Image Recovery/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Image_Recovery"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Image_Recovery.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Image_Recovery.dir/build: Image_Recovery
.PHONY : CMakeFiles/Image_Recovery.dir/build

CMakeFiles/Image_Recovery.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Image_Recovery.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Image_Recovery.dir/clean

CMakeFiles/Image_Recovery.dir/depend:
	cd "/home/n4ssser/Image-Recovery/Image Recovery/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/n4ssser/Image-Recovery/Image Recovery" "/home/n4ssser/Image-Recovery/Image Recovery" "/home/n4ssser/Image-Recovery/Image Recovery/cmake-build-debug" "/home/n4ssser/Image-Recovery/Image Recovery/cmake-build-debug" "/home/n4ssser/Image-Recovery/Image Recovery/cmake-build-debug/CMakeFiles/Image_Recovery.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Image_Recovery.dir/depend
