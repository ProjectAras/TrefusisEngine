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
CMAKE_COMMAND = /home/elsa/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/193.6911.21/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/elsa/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/193.6911.21/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/elsa/CLionProjects/TrefusisEngine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/elsa/CLionProjects/TrefusisEngine/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/TrefusisEngine.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TrefusisEngine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TrefusisEngine.dir/flags.make

CMakeFiles/TrefusisEngine.dir/src/main.cpp.o: CMakeFiles/TrefusisEngine.dir/flags.make
CMakeFiles/TrefusisEngine.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/elsa/CLionProjects/TrefusisEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TrefusisEngine.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TrefusisEngine.dir/src/main.cpp.o -c /home/elsa/CLionProjects/TrefusisEngine/src/main.cpp

CMakeFiles/TrefusisEngine.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TrefusisEngine.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/elsa/CLionProjects/TrefusisEngine/src/main.cpp > CMakeFiles/TrefusisEngine.dir/src/main.cpp.i

CMakeFiles/TrefusisEngine.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TrefusisEngine.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/elsa/CLionProjects/TrefusisEngine/src/main.cpp -o CMakeFiles/TrefusisEngine.dir/src/main.cpp.s

CMakeFiles/TrefusisEngine.dir/src/objects/Actor.cpp.o: CMakeFiles/TrefusisEngine.dir/flags.make
CMakeFiles/TrefusisEngine.dir/src/objects/Actor.cpp.o: ../src/objects/Actor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/elsa/CLionProjects/TrefusisEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TrefusisEngine.dir/src/objects/Actor.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TrefusisEngine.dir/src/objects/Actor.cpp.o -c /home/elsa/CLionProjects/TrefusisEngine/src/objects/Actor.cpp

CMakeFiles/TrefusisEngine.dir/src/objects/Actor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TrefusisEngine.dir/src/objects/Actor.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/elsa/CLionProjects/TrefusisEngine/src/objects/Actor.cpp > CMakeFiles/TrefusisEngine.dir/src/objects/Actor.cpp.i

CMakeFiles/TrefusisEngine.dir/src/objects/Actor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TrefusisEngine.dir/src/objects/Actor.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/elsa/CLionProjects/TrefusisEngine/src/objects/Actor.cpp -o CMakeFiles/TrefusisEngine.dir/src/objects/Actor.cpp.s

CMakeFiles/TrefusisEngine.dir/src/objects/EnviromentalActor.cpp.o: CMakeFiles/TrefusisEngine.dir/flags.make
CMakeFiles/TrefusisEngine.dir/src/objects/EnviromentalActor.cpp.o: ../src/objects/EnviromentalActor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/elsa/CLionProjects/TrefusisEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/TrefusisEngine.dir/src/objects/EnviromentalActor.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TrefusisEngine.dir/src/objects/EnviromentalActor.cpp.o -c /home/elsa/CLionProjects/TrefusisEngine/src/objects/EnviromentalActor.cpp

CMakeFiles/TrefusisEngine.dir/src/objects/EnviromentalActor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TrefusisEngine.dir/src/objects/EnviromentalActor.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/elsa/CLionProjects/TrefusisEngine/src/objects/EnviromentalActor.cpp > CMakeFiles/TrefusisEngine.dir/src/objects/EnviromentalActor.cpp.i

CMakeFiles/TrefusisEngine.dir/src/objects/EnviromentalActor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TrefusisEngine.dir/src/objects/EnviromentalActor.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/elsa/CLionProjects/TrefusisEngine/src/objects/EnviromentalActor.cpp -o CMakeFiles/TrefusisEngine.dir/src/objects/EnviromentalActor.cpp.s

CMakeFiles/TrefusisEngine.dir/src/utility/FileReader.cpp.o: CMakeFiles/TrefusisEngine.dir/flags.make
CMakeFiles/TrefusisEngine.dir/src/utility/FileReader.cpp.o: ../src/utility/FileReader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/elsa/CLionProjects/TrefusisEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/TrefusisEngine.dir/src/utility/FileReader.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TrefusisEngine.dir/src/utility/FileReader.cpp.o -c /home/elsa/CLionProjects/TrefusisEngine/src/utility/FileReader.cpp

CMakeFiles/TrefusisEngine.dir/src/utility/FileReader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TrefusisEngine.dir/src/utility/FileReader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/elsa/CLionProjects/TrefusisEngine/src/utility/FileReader.cpp > CMakeFiles/TrefusisEngine.dir/src/utility/FileReader.cpp.i

CMakeFiles/TrefusisEngine.dir/src/utility/FileReader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TrefusisEngine.dir/src/utility/FileReader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/elsa/CLionProjects/TrefusisEngine/src/utility/FileReader.cpp -o CMakeFiles/TrefusisEngine.dir/src/utility/FileReader.cpp.s

CMakeFiles/TrefusisEngine.dir/src/managers/GameManager.cpp.o: CMakeFiles/TrefusisEngine.dir/flags.make
CMakeFiles/TrefusisEngine.dir/src/managers/GameManager.cpp.o: ../src/managers/GameManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/elsa/CLionProjects/TrefusisEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/TrefusisEngine.dir/src/managers/GameManager.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TrefusisEngine.dir/src/managers/GameManager.cpp.o -c /home/elsa/CLionProjects/TrefusisEngine/src/managers/GameManager.cpp

CMakeFiles/TrefusisEngine.dir/src/managers/GameManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TrefusisEngine.dir/src/managers/GameManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/elsa/CLionProjects/TrefusisEngine/src/managers/GameManager.cpp > CMakeFiles/TrefusisEngine.dir/src/managers/GameManager.cpp.i

CMakeFiles/TrefusisEngine.dir/src/managers/GameManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TrefusisEngine.dir/src/managers/GameManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/elsa/CLionProjects/TrefusisEngine/src/managers/GameManager.cpp -o CMakeFiles/TrefusisEngine.dir/src/managers/GameManager.cpp.s

CMakeFiles/TrefusisEngine.dir/src/objects/Character.cpp.o: CMakeFiles/TrefusisEngine.dir/flags.make
CMakeFiles/TrefusisEngine.dir/src/objects/Character.cpp.o: ../src/objects/Character.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/elsa/CLionProjects/TrefusisEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/TrefusisEngine.dir/src/objects/Character.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TrefusisEngine.dir/src/objects/Character.cpp.o -c /home/elsa/CLionProjects/TrefusisEngine/src/objects/Character.cpp

CMakeFiles/TrefusisEngine.dir/src/objects/Character.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TrefusisEngine.dir/src/objects/Character.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/elsa/CLionProjects/TrefusisEngine/src/objects/Character.cpp > CMakeFiles/TrefusisEngine.dir/src/objects/Character.cpp.i

CMakeFiles/TrefusisEngine.dir/src/objects/Character.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TrefusisEngine.dir/src/objects/Character.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/elsa/CLionProjects/TrefusisEngine/src/objects/Character.cpp -o CMakeFiles/TrefusisEngine.dir/src/objects/Character.cpp.s

# Object files for target TrefusisEngine
TrefusisEngine_OBJECTS = \
"CMakeFiles/TrefusisEngine.dir/src/main.cpp.o" \
"CMakeFiles/TrefusisEngine.dir/src/objects/Actor.cpp.o" \
"CMakeFiles/TrefusisEngine.dir/src/objects/EnviromentalActor.cpp.o" \
"CMakeFiles/TrefusisEngine.dir/src/utility/FileReader.cpp.o" \
"CMakeFiles/TrefusisEngine.dir/src/managers/GameManager.cpp.o" \
"CMakeFiles/TrefusisEngine.dir/src/objects/Character.cpp.o"

# External object files for target TrefusisEngine
TrefusisEngine_EXTERNAL_OBJECTS =

TrefusisEngine: CMakeFiles/TrefusisEngine.dir/src/main.cpp.o
TrefusisEngine: CMakeFiles/TrefusisEngine.dir/src/objects/Actor.cpp.o
TrefusisEngine: CMakeFiles/TrefusisEngine.dir/src/objects/EnviromentalActor.cpp.o
TrefusisEngine: CMakeFiles/TrefusisEngine.dir/src/utility/FileReader.cpp.o
TrefusisEngine: CMakeFiles/TrefusisEngine.dir/src/managers/GameManager.cpp.o
TrefusisEngine: CMakeFiles/TrefusisEngine.dir/src/objects/Character.cpp.o
TrefusisEngine: CMakeFiles/TrefusisEngine.dir/build.make
TrefusisEngine: CMakeFiles/TrefusisEngine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/elsa/CLionProjects/TrefusisEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable TrefusisEngine"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TrefusisEngine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TrefusisEngine.dir/build: TrefusisEngine

.PHONY : CMakeFiles/TrefusisEngine.dir/build

CMakeFiles/TrefusisEngine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TrefusisEngine.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TrefusisEngine.dir/clean

CMakeFiles/TrefusisEngine.dir/depend:
	cd /home/elsa/CLionProjects/TrefusisEngine/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/elsa/CLionProjects/TrefusisEngine /home/elsa/CLionProjects/TrefusisEngine /home/elsa/CLionProjects/TrefusisEngine/cmake-build-debug /home/elsa/CLionProjects/TrefusisEngine/cmake-build-debug /home/elsa/CLionProjects/TrefusisEngine/cmake-build-debug/CMakeFiles/TrefusisEngine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TrefusisEngine.dir/depend

