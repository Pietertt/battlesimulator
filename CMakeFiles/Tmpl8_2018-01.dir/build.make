# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/pieterboersma/Desktop/battlesimulator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/pieterboersma/Desktop/battlesimulator

# Include any dependencies generated for this target.
include CMakeFiles/Tmpl8_2018-01.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Tmpl8_2018-01.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Tmpl8_2018-01.dir/flags.make

CMakeFiles/Tmpl8_2018-01.dir/src/explosion.cpp.o: CMakeFiles/Tmpl8_2018-01.dir/flags.make
CMakeFiles/Tmpl8_2018-01.dir/src/explosion.cpp.o: src/explosion.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/pieterboersma/Desktop/battlesimulator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Tmpl8_2018-01.dir/src/explosion.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tmpl8_2018-01.dir/src/explosion.cpp.o -c /Users/pieterboersma/Desktop/battlesimulator/src/explosion.cpp

CMakeFiles/Tmpl8_2018-01.dir/src/explosion.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tmpl8_2018-01.dir/src/explosion.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/pieterboersma/Desktop/battlesimulator/src/explosion.cpp > CMakeFiles/Tmpl8_2018-01.dir/src/explosion.cpp.i

CMakeFiles/Tmpl8_2018-01.dir/src/explosion.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tmpl8_2018-01.dir/src/explosion.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/pieterboersma/Desktop/battlesimulator/src/explosion.cpp -o CMakeFiles/Tmpl8_2018-01.dir/src/explosion.cpp.s

CMakeFiles/Tmpl8_2018-01.dir/src/game.cpp.o: CMakeFiles/Tmpl8_2018-01.dir/flags.make
CMakeFiles/Tmpl8_2018-01.dir/src/game.cpp.o: src/game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/pieterboersma/Desktop/battlesimulator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Tmpl8_2018-01.dir/src/game.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tmpl8_2018-01.dir/src/game.cpp.o -c /Users/pieterboersma/Desktop/battlesimulator/src/game.cpp

CMakeFiles/Tmpl8_2018-01.dir/src/game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tmpl8_2018-01.dir/src/game.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/pieterboersma/Desktop/battlesimulator/src/game.cpp > CMakeFiles/Tmpl8_2018-01.dir/src/game.cpp.i

CMakeFiles/Tmpl8_2018-01.dir/src/game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tmpl8_2018-01.dir/src/game.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/pieterboersma/Desktop/battlesimulator/src/game.cpp -o CMakeFiles/Tmpl8_2018-01.dir/src/game.cpp.s

CMakeFiles/Tmpl8_2018-01.dir/src/particle_beam.cpp.o: CMakeFiles/Tmpl8_2018-01.dir/flags.make
CMakeFiles/Tmpl8_2018-01.dir/src/particle_beam.cpp.o: src/particle_beam.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/pieterboersma/Desktop/battlesimulator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Tmpl8_2018-01.dir/src/particle_beam.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tmpl8_2018-01.dir/src/particle_beam.cpp.o -c /Users/pieterboersma/Desktop/battlesimulator/src/particle_beam.cpp

CMakeFiles/Tmpl8_2018-01.dir/src/particle_beam.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tmpl8_2018-01.dir/src/particle_beam.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/pieterboersma/Desktop/battlesimulator/src/particle_beam.cpp > CMakeFiles/Tmpl8_2018-01.dir/src/particle_beam.cpp.i

CMakeFiles/Tmpl8_2018-01.dir/src/particle_beam.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tmpl8_2018-01.dir/src/particle_beam.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/pieterboersma/Desktop/battlesimulator/src/particle_beam.cpp -o CMakeFiles/Tmpl8_2018-01.dir/src/particle_beam.cpp.s

CMakeFiles/Tmpl8_2018-01.dir/src/rocket.cpp.o: CMakeFiles/Tmpl8_2018-01.dir/flags.make
CMakeFiles/Tmpl8_2018-01.dir/src/rocket.cpp.o: src/rocket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/pieterboersma/Desktop/battlesimulator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Tmpl8_2018-01.dir/src/rocket.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tmpl8_2018-01.dir/src/rocket.cpp.o -c /Users/pieterboersma/Desktop/battlesimulator/src/rocket.cpp

CMakeFiles/Tmpl8_2018-01.dir/src/rocket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tmpl8_2018-01.dir/src/rocket.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/pieterboersma/Desktop/battlesimulator/src/rocket.cpp > CMakeFiles/Tmpl8_2018-01.dir/src/rocket.cpp.i

CMakeFiles/Tmpl8_2018-01.dir/src/rocket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tmpl8_2018-01.dir/src/rocket.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/pieterboersma/Desktop/battlesimulator/src/rocket.cpp -o CMakeFiles/Tmpl8_2018-01.dir/src/rocket.cpp.s

CMakeFiles/Tmpl8_2018-01.dir/src/smoke.cpp.o: CMakeFiles/Tmpl8_2018-01.dir/flags.make
CMakeFiles/Tmpl8_2018-01.dir/src/smoke.cpp.o: src/smoke.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/pieterboersma/Desktop/battlesimulator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Tmpl8_2018-01.dir/src/smoke.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tmpl8_2018-01.dir/src/smoke.cpp.o -c /Users/pieterboersma/Desktop/battlesimulator/src/smoke.cpp

CMakeFiles/Tmpl8_2018-01.dir/src/smoke.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tmpl8_2018-01.dir/src/smoke.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/pieterboersma/Desktop/battlesimulator/src/smoke.cpp > CMakeFiles/Tmpl8_2018-01.dir/src/smoke.cpp.i

CMakeFiles/Tmpl8_2018-01.dir/src/smoke.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tmpl8_2018-01.dir/src/smoke.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/pieterboersma/Desktop/battlesimulator/src/smoke.cpp -o CMakeFiles/Tmpl8_2018-01.dir/src/smoke.cpp.s

CMakeFiles/Tmpl8_2018-01.dir/src/surface.cpp.o: CMakeFiles/Tmpl8_2018-01.dir/flags.make
CMakeFiles/Tmpl8_2018-01.dir/src/surface.cpp.o: src/surface.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/pieterboersma/Desktop/battlesimulator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Tmpl8_2018-01.dir/src/surface.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tmpl8_2018-01.dir/src/surface.cpp.o -c /Users/pieterboersma/Desktop/battlesimulator/src/surface.cpp

CMakeFiles/Tmpl8_2018-01.dir/src/surface.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tmpl8_2018-01.dir/src/surface.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/pieterboersma/Desktop/battlesimulator/src/surface.cpp > CMakeFiles/Tmpl8_2018-01.dir/src/surface.cpp.i

CMakeFiles/Tmpl8_2018-01.dir/src/surface.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tmpl8_2018-01.dir/src/surface.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/pieterboersma/Desktop/battlesimulator/src/surface.cpp -o CMakeFiles/Tmpl8_2018-01.dir/src/surface.cpp.s

CMakeFiles/Tmpl8_2018-01.dir/src/tank.cpp.o: CMakeFiles/Tmpl8_2018-01.dir/flags.make
CMakeFiles/Tmpl8_2018-01.dir/src/tank.cpp.o: src/tank.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/pieterboersma/Desktop/battlesimulator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Tmpl8_2018-01.dir/src/tank.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tmpl8_2018-01.dir/src/tank.cpp.o -c /Users/pieterboersma/Desktop/battlesimulator/src/tank.cpp

CMakeFiles/Tmpl8_2018-01.dir/src/tank.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tmpl8_2018-01.dir/src/tank.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/pieterboersma/Desktop/battlesimulator/src/tank.cpp > CMakeFiles/Tmpl8_2018-01.dir/src/tank.cpp.i

CMakeFiles/Tmpl8_2018-01.dir/src/tank.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tmpl8_2018-01.dir/src/tank.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/pieterboersma/Desktop/battlesimulator/src/tank.cpp -o CMakeFiles/Tmpl8_2018-01.dir/src/tank.cpp.s

CMakeFiles/Tmpl8_2018-01.dir/src/template.cpp.o: CMakeFiles/Tmpl8_2018-01.dir/flags.make
CMakeFiles/Tmpl8_2018-01.dir/src/template.cpp.o: src/template.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/pieterboersma/Desktop/battlesimulator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Tmpl8_2018-01.dir/src/template.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tmpl8_2018-01.dir/src/template.cpp.o -c /Users/pieterboersma/Desktop/battlesimulator/src/template.cpp

CMakeFiles/Tmpl8_2018-01.dir/src/template.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tmpl8_2018-01.dir/src/template.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/pieterboersma/Desktop/battlesimulator/src/template.cpp > CMakeFiles/Tmpl8_2018-01.dir/src/template.cpp.i

CMakeFiles/Tmpl8_2018-01.dir/src/template.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tmpl8_2018-01.dir/src/template.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/pieterboersma/Desktop/battlesimulator/src/template.cpp -o CMakeFiles/Tmpl8_2018-01.dir/src/template.cpp.s

# Object files for target Tmpl8_2018-01
Tmpl8_2018__01_OBJECTS = \
"CMakeFiles/Tmpl8_2018-01.dir/src/explosion.cpp.o" \
"CMakeFiles/Tmpl8_2018-01.dir/src/game.cpp.o" \
"CMakeFiles/Tmpl8_2018-01.dir/src/particle_beam.cpp.o" \
"CMakeFiles/Tmpl8_2018-01.dir/src/rocket.cpp.o" \
"CMakeFiles/Tmpl8_2018-01.dir/src/smoke.cpp.o" \
"CMakeFiles/Tmpl8_2018-01.dir/src/surface.cpp.o" \
"CMakeFiles/Tmpl8_2018-01.dir/src/tank.cpp.o" \
"CMakeFiles/Tmpl8_2018-01.dir/src/template.cpp.o"

# External object files for target Tmpl8_2018-01
Tmpl8_2018__01_EXTERNAL_OBJECTS =

Tmpl8_2018-01: CMakeFiles/Tmpl8_2018-01.dir/src/explosion.cpp.o
Tmpl8_2018-01: CMakeFiles/Tmpl8_2018-01.dir/src/game.cpp.o
Tmpl8_2018-01: CMakeFiles/Tmpl8_2018-01.dir/src/particle_beam.cpp.o
Tmpl8_2018-01: CMakeFiles/Tmpl8_2018-01.dir/src/rocket.cpp.o
Tmpl8_2018-01: CMakeFiles/Tmpl8_2018-01.dir/src/smoke.cpp.o
Tmpl8_2018-01: CMakeFiles/Tmpl8_2018-01.dir/src/surface.cpp.o
Tmpl8_2018-01: CMakeFiles/Tmpl8_2018-01.dir/src/tank.cpp.o
Tmpl8_2018-01: CMakeFiles/Tmpl8_2018-01.dir/src/template.cpp.o
Tmpl8_2018-01: CMakeFiles/Tmpl8_2018-01.dir/build.make
Tmpl8_2018-01: /System/Library/Frameworks/OpenGL.framework/OpenGL.tbd
Tmpl8_2018-01: /usr/local/lib/libGLEW.2.2.0.dylib
Tmpl8_2018-01: /usr/local/Cellar/sdl2/2.0.12_1/lib/libSDL2.dylib
Tmpl8_2018-01: /usr/local/lib/libfreeimage.dylib
Tmpl8_2018-01: CMakeFiles/Tmpl8_2018-01.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/pieterboersma/Desktop/battlesimulator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable Tmpl8_2018-01"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Tmpl8_2018-01.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Tmpl8_2018-01.dir/build: Tmpl8_2018-01

.PHONY : CMakeFiles/Tmpl8_2018-01.dir/build

CMakeFiles/Tmpl8_2018-01.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Tmpl8_2018-01.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Tmpl8_2018-01.dir/clean

CMakeFiles/Tmpl8_2018-01.dir/depend:
	cd /Users/pieterboersma/Desktop/battlesimulator && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/pieterboersma/Desktop/battlesimulator /Users/pieterboersma/Desktop/battlesimulator /Users/pieterboersma/Desktop/battlesimulator /Users/pieterboersma/Desktop/battlesimulator /Users/pieterboersma/Desktop/battlesimulator/CMakeFiles/Tmpl8_2018-01.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Tmpl8_2018-01.dir/depend
