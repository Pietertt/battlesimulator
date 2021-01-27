# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.18.4/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.18.4/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/pieterboersma/Desktop/battlesimulator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/pieterboersma/Desktop/battlesimulator

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/local/Cellar/cmake/3.18.4/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/local/Cellar/cmake/3.18.4/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/pieterboersma/Desktop/battlesimulator/CMakeFiles /Users/pieterboersma/Desktop/battlesimulator//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/pieterboersma/Desktop/battlesimulator/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named battlesimulator

# Build rule for target.
battlesimulator: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 battlesimulator
.PHONY : battlesimulator

# fast build rule for target.
battlesimulator/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/battlesimulator.dir/build.make CMakeFiles/battlesimulator.dir/build
.PHONY : battlesimulator/fast

src/explosion.o: src/explosion.cpp.o

.PHONY : src/explosion.o

# target to build an object file
src/explosion.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/battlesimulator.dir/build.make CMakeFiles/battlesimulator.dir/src/explosion.cpp.o
.PHONY : src/explosion.cpp.o

src/explosion.i: src/explosion.cpp.i

.PHONY : src/explosion.i

# target to preprocess a source file
src/explosion.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/battlesimulator.dir/build.make CMakeFiles/battlesimulator.dir/src/explosion.cpp.i
.PHONY : src/explosion.cpp.i

src/explosion.s: src/explosion.cpp.s

.PHONY : src/explosion.s

# target to generate assembly for a file
src/explosion.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/battlesimulator.dir/build.make CMakeFiles/battlesimulator.dir/src/explosion.cpp.s
.PHONY : src/explosion.cpp.s

src/game.o: src/game.cpp.o

.PHONY : src/game.o

# target to build an object file
src/game.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/battlesimulator.dir/build.make CMakeFiles/battlesimulator.dir/src/game.cpp.o
.PHONY : src/game.cpp.o

src/game.i: src/game.cpp.i

.PHONY : src/game.i

# target to preprocess a source file
src/game.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/battlesimulator.dir/build.make CMakeFiles/battlesimulator.dir/src/game.cpp.i
.PHONY : src/game.cpp.i

src/game.s: src/game.cpp.s

.PHONY : src/game.s

# target to generate assembly for a file
src/game.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/battlesimulator.dir/build.make CMakeFiles/battlesimulator.dir/src/game.cpp.s
.PHONY : src/game.cpp.s

src/grid.o: src/grid.cpp.o

.PHONY : src/grid.o

# target to build an object file
src/grid.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/battlesimulator.dir/build.make CMakeFiles/battlesimulator.dir/src/grid.cpp.o
.PHONY : src/grid.cpp.o

src/grid.i: src/grid.cpp.i

.PHONY : src/grid.i

# target to preprocess a source file
src/grid.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/battlesimulator.dir/build.make CMakeFiles/battlesimulator.dir/src/grid.cpp.i
.PHONY : src/grid.cpp.i

src/grid.s: src/grid.cpp.s

.PHONY : src/grid.s

# target to generate assembly for a file
src/grid.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/battlesimulator.dir/build.make CMakeFiles/battlesimulator.dir/src/grid.cpp.s
.PHONY : src/grid.cpp.s

src/kdtree.o: src/kdtree.cpp.o

.PHONY : src/kdtree.o

# target to build an object file
src/kdtree.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/battlesimulator.dir/build.make CMakeFiles/battlesimulator.dir/src/kdtree.cpp.o
.PHONY : src/kdtree.cpp.o

src/kdtree.i: src/kdtree.cpp.i

.PHONY : src/kdtree.i

# target to preprocess a source file
src/kdtree.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/battlesimulator.dir/build.make CMakeFiles/battlesimulator.dir/src/kdtree.cpp.i
.PHONY : src/kdtree.cpp.i

src/kdtree.s: src/kdtree.cpp.s

.PHONY : src/kdtree.s

# target to generate assembly for a file
src/kdtree.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/battlesimulator.dir/build.make CMakeFiles/battlesimulator.dir/src/kdtree.cpp.s
.PHONY : src/kdtree.cpp.s

src/particle_beam.o: src/particle_beam.cpp.o

.PHONY : src/particle_beam.o

# target to build an object file
src/particle_beam.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/battlesimulator.dir/build.make CMakeFiles/battlesimulator.dir/src/particle_beam.cpp.o
.PHONY : src/particle_beam.cpp.o

src/particle_beam.i: src/particle_beam.cpp.i

.PHONY : src/particle_beam.i

# target to preprocess a source file
src/particle_beam.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/battlesimulator.dir/build.make CMakeFiles/battlesimulator.dir/src/particle_beam.cpp.i
.PHONY : src/particle_beam.cpp.i

src/particle_beam.s: src/particle_beam.cpp.s

.PHONY : src/particle_beam.s

# target to generate assembly for a file
src/particle_beam.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/battlesimulator.dir/build.make CMakeFiles/battlesimulator.dir/src/particle_beam.cpp.s
.PHONY : src/particle_beam.cpp.s

src/rocket.o: src/rocket.cpp.o

.PHONY : src/rocket.o

# target to build an object file
src/rocket.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/battlesimulator.dir/build.make CMakeFiles/battlesimulator.dir/src/rocket.cpp.o
.PHONY : src/rocket.cpp.o

src/rocket.i: src/rocket.cpp.i

.PHONY : src/rocket.i

# target to preprocess a source file
src/rocket.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/battlesimulator.dir/build.make CMakeFiles/battlesimulator.dir/src/rocket.cpp.i
.PHONY : src/rocket.cpp.i

src/rocket.s: src/rocket.cpp.s

.PHONY : src/rocket.s

# target to generate assembly for a file
src/rocket.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/battlesimulator.dir/build.make CMakeFiles/battlesimulator.dir/src/rocket.cpp.s
.PHONY : src/rocket.cpp.s

src/smoke.o: src/smoke.cpp.o

.PHONY : src/smoke.o

# target to build an object file
src/smoke.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/battlesimulator.dir/build.make CMakeFiles/battlesimulator.dir/src/smoke.cpp.o
.PHONY : src/smoke.cpp.o

src/smoke.i: src/smoke.cpp.i

.PHONY : src/smoke.i

# target to preprocess a source file
src/smoke.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/battlesimulator.dir/build.make CMakeFiles/battlesimulator.dir/src/smoke.cpp.i
.PHONY : src/smoke.cpp.i

src/smoke.s: src/smoke.cpp.s

.PHONY : src/smoke.s

# target to generate assembly for a file
src/smoke.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/battlesimulator.dir/build.make CMakeFiles/battlesimulator.dir/src/smoke.cpp.s
.PHONY : src/smoke.cpp.s

src/surface.o: src/surface.cpp.o

.PHONY : src/surface.o

# target to build an object file
src/surface.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/battlesimulator.dir/build.make CMakeFiles/battlesimulator.dir/src/surface.cpp.o
.PHONY : src/surface.cpp.o

src/surface.i: src/surface.cpp.i

.PHONY : src/surface.i

# target to preprocess a source file
src/surface.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/battlesimulator.dir/build.make CMakeFiles/battlesimulator.dir/src/surface.cpp.i
.PHONY : src/surface.cpp.i

src/surface.s: src/surface.cpp.s

.PHONY : src/surface.s

# target to generate assembly for a file
src/surface.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/battlesimulator.dir/build.make CMakeFiles/battlesimulator.dir/src/surface.cpp.s
.PHONY : src/surface.cpp.s

src/tank.o: src/tank.cpp.o

.PHONY : src/tank.o

# target to build an object file
src/tank.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/battlesimulator.dir/build.make CMakeFiles/battlesimulator.dir/src/tank.cpp.o
.PHONY : src/tank.cpp.o

src/tank.i: src/tank.cpp.i

.PHONY : src/tank.i

# target to preprocess a source file
src/tank.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/battlesimulator.dir/build.make CMakeFiles/battlesimulator.dir/src/tank.cpp.i
.PHONY : src/tank.cpp.i

src/tank.s: src/tank.cpp.s

.PHONY : src/tank.s

# target to generate assembly for a file
src/tank.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/battlesimulator.dir/build.make CMakeFiles/battlesimulator.dir/src/tank.cpp.s
.PHONY : src/tank.cpp.s

src/template.o: src/template.cpp.o

.PHONY : src/template.o

# target to build an object file
src/template.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/battlesimulator.dir/build.make CMakeFiles/battlesimulator.dir/src/template.cpp.o
.PHONY : src/template.cpp.o

src/template.i: src/template.cpp.i

.PHONY : src/template.i

# target to preprocess a source file
src/template.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/battlesimulator.dir/build.make CMakeFiles/battlesimulator.dir/src/template.cpp.i
.PHONY : src/template.cpp.i

src/template.s: src/template.cpp.s

.PHONY : src/template.s

# target to generate assembly for a file
src/template.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/battlesimulator.dir/build.make CMakeFiles/battlesimulator.dir/src/template.cpp.s
.PHONY : src/template.cpp.s

src/threading/threadpool.o: src/threading/threadpool.cpp.o

.PHONY : src/threading/threadpool.o

# target to build an object file
src/threading/threadpool.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/battlesimulator.dir/build.make CMakeFiles/battlesimulator.dir/src/threading/threadpool.cpp.o
.PHONY : src/threading/threadpool.cpp.o

src/threading/threadpool.i: src/threading/threadpool.cpp.i

.PHONY : src/threading/threadpool.i

# target to preprocess a source file
src/threading/threadpool.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/battlesimulator.dir/build.make CMakeFiles/battlesimulator.dir/src/threading/threadpool.cpp.i
.PHONY : src/threading/threadpool.cpp.i

src/threading/threadpool.s: src/threading/threadpool.cpp.s

.PHONY : src/threading/threadpool.s

# target to generate assembly for a file
src/threading/threadpool.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/battlesimulator.dir/build.make CMakeFiles/battlesimulator.dir/src/threading/threadpool.cpp.s
.PHONY : src/threading/threadpool.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... battlesimulator"
	@echo "... src/explosion.o"
	@echo "... src/explosion.i"
	@echo "... src/explosion.s"
	@echo "... src/game.o"
	@echo "... src/game.i"
	@echo "... src/game.s"
	@echo "... src/grid.o"
	@echo "... src/grid.i"
	@echo "... src/grid.s"
	@echo "... src/kdtree.o"
	@echo "... src/kdtree.i"
	@echo "... src/kdtree.s"
	@echo "... src/particle_beam.o"
	@echo "... src/particle_beam.i"
	@echo "... src/particle_beam.s"
	@echo "... src/rocket.o"
	@echo "... src/rocket.i"
	@echo "... src/rocket.s"
	@echo "... src/smoke.o"
	@echo "... src/smoke.i"
	@echo "... src/smoke.s"
	@echo "... src/surface.o"
	@echo "... src/surface.i"
	@echo "... src/surface.s"
	@echo "... src/tank.o"
	@echo "... src/tank.i"
	@echo "... src/tank.s"
	@echo "... src/template.o"
	@echo "... src/template.i"
	@echo "... src/template.s"
	@echo "... src/threading/threadpool.o"
	@echo "... src/threading/threadpool.i"
	@echo "... src/threading/threadpool.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

