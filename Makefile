# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_SOURCE_DIR = /home/tapas/Jet-Fighter-Plane-Simulator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tapas/Jet-Fighter-Plane-Simulator

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/tapas/Jet-Fighter-Plane-Simulator/CMakeFiles /home/tapas/Jet-Fighter-Plane-Simulator/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/tapas/Jet-Fighter-Plane-Simulator/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named graphics_asgn1

# Build rule for target.
graphics_asgn1: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 graphics_asgn1
.PHONY : graphics_asgn1

# fast build rule for target.
graphics_asgn1/fast:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/build
.PHONY : graphics_asgn1/fast

src/airspeed.o: src/airspeed.cpp.o

.PHONY : src/airspeed.o

# target to build an object file
src/airspeed.cpp.o:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/airspeed.cpp.o
.PHONY : src/airspeed.cpp.o

src/airspeed.i: src/airspeed.cpp.i

.PHONY : src/airspeed.i

# target to preprocess a source file
src/airspeed.cpp.i:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/airspeed.cpp.i
.PHONY : src/airspeed.cpp.i

src/airspeed.s: src/airspeed.cpp.s

.PHONY : src/airspeed.s

# target to generate assembly for a file
src/airspeed.cpp.s:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/airspeed.cpp.s
.PHONY : src/airspeed.cpp.s

src/altimeter.o: src/altimeter.cpp.o

.PHONY : src/altimeter.o

# target to build an object file
src/altimeter.cpp.o:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/altimeter.cpp.o
.PHONY : src/altimeter.cpp.o

src/altimeter.i: src/altimeter.cpp.i

.PHONY : src/altimeter.i

# target to preprocess a source file
src/altimeter.cpp.i:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/altimeter.cpp.i
.PHONY : src/altimeter.cpp.i

src/altimeter.s: src/altimeter.cpp.s

.PHONY : src/altimeter.s

# target to generate assembly for a file
src/altimeter.cpp.s:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/altimeter.cpp.s
.PHONY : src/altimeter.cpp.s

src/ball.o: src/ball.cpp.o

.PHONY : src/ball.o

# target to build an object file
src/ball.cpp.o:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/ball.cpp.o
.PHONY : src/ball.cpp.o

src/ball.i: src/ball.cpp.i

.PHONY : src/ball.i

# target to preprocess a source file
src/ball.cpp.i:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/ball.cpp.i
.PHONY : src/ball.cpp.i

src/ball.s: src/ball.cpp.s

.PHONY : src/ball.s

# target to generate assembly for a file
src/ball.cpp.s:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/ball.cpp.s
.PHONY : src/ball.cpp.s

src/bomb.o: src/bomb.cpp.o

.PHONY : src/bomb.o

# target to build an object file
src/bomb.cpp.o:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/bomb.cpp.o
.PHONY : src/bomb.cpp.o

src/bomb.i: src/bomb.cpp.i

.PHONY : src/bomb.i

# target to preprocess a source file
src/bomb.cpp.i:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/bomb.cpp.i
.PHONY : src/bomb.cpp.i

src/bomb.s: src/bomb.cpp.s

.PHONY : src/bomb.s

# target to generate assembly for a file
src/bomb.cpp.s:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/bomb.cpp.s
.PHONY : src/bomb.cpp.s

src/color.o: src/color.cpp.o

.PHONY : src/color.o

# target to build an object file
src/color.cpp.o:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/color.cpp.o
.PHONY : src/color.cpp.o

src/color.i: src/color.cpp.i

.PHONY : src/color.i

# target to preprocess a source file
src/color.cpp.i:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/color.cpp.i
.PHONY : src/color.cpp.i

src/color.s: src/color.cpp.s

.PHONY : src/color.s

# target to generate assembly for a file
src/color.cpp.s:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/color.cpp.s
.PHONY : src/color.cpp.s

src/enemy.o: src/enemy.cpp.o

.PHONY : src/enemy.o

# target to build an object file
src/enemy.cpp.o:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/enemy.cpp.o
.PHONY : src/enemy.cpp.o

src/enemy.i: src/enemy.cpp.i

.PHONY : src/enemy.i

# target to preprocess a source file
src/enemy.cpp.i:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/enemy.cpp.i
.PHONY : src/enemy.cpp.i

src/enemy.s: src/enemy.cpp.s

.PHONY : src/enemy.s

# target to generate assembly for a file
src/enemy.cpp.s:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/enemy.cpp.s
.PHONY : src/enemy.cpp.s

src/enemy_missile.o: src/enemy_missile.cpp.o

.PHONY : src/enemy_missile.o

# target to build an object file
src/enemy_missile.cpp.o:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/enemy_missile.cpp.o
.PHONY : src/enemy_missile.cpp.o

src/enemy_missile.i: src/enemy_missile.cpp.i

.PHONY : src/enemy_missile.i

# target to preprocess a source file
src/enemy_missile.cpp.i:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/enemy_missile.cpp.i
.PHONY : src/enemy_missile.cpp.i

src/enemy_missile.s: src/enemy_missile.cpp.s

.PHONY : src/enemy_missile.s

# target to generate assembly for a file
src/enemy_missile.cpp.s:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/enemy_missile.cpp.s
.PHONY : src/enemy_missile.cpp.s

src/fuel_bar.o: src/fuel_bar.cpp.o

.PHONY : src/fuel_bar.o

# target to build an object file
src/fuel_bar.cpp.o:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/fuel_bar.cpp.o
.PHONY : src/fuel_bar.cpp.o

src/fuel_bar.i: src/fuel_bar.cpp.i

.PHONY : src/fuel_bar.i

# target to preprocess a source file
src/fuel_bar.cpp.i:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/fuel_bar.cpp.i
.PHONY : src/fuel_bar.cpp.i

src/fuel_bar.s: src/fuel_bar.cpp.s

.PHONY : src/fuel_bar.s

# target to generate assembly for a file
src/fuel_bar.cpp.s:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/fuel_bar.cpp.s
.PHONY : src/fuel_bar.cpp.s

src/input.o: src/input.cpp.o

.PHONY : src/input.o

# target to build an object file
src/input.cpp.o:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/input.cpp.o
.PHONY : src/input.cpp.o

src/input.i: src/input.cpp.i

.PHONY : src/input.i

# target to preprocess a source file
src/input.cpp.i:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/input.cpp.i
.PHONY : src/input.cpp.i

src/input.s: src/input.cpp.s

.PHONY : src/input.s

# target to generate assembly for a file
src/input.cpp.s:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/input.cpp.s
.PHONY : src/input.cpp.s

src/main.o: src/main.cpp.o

.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

src/marker.o: src/marker.cpp.o

.PHONY : src/marker.o

# target to build an object file
src/marker.cpp.o:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/marker.cpp.o
.PHONY : src/marker.cpp.o

src/marker.i: src/marker.cpp.i

.PHONY : src/marker.i

# target to preprocess a source file
src/marker.cpp.i:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/marker.cpp.i
.PHONY : src/marker.cpp.i

src/marker.s: src/marker.cpp.s

.PHONY : src/marker.s

# target to generate assembly for a file
src/marker.cpp.s:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/marker.cpp.s
.PHONY : src/marker.cpp.s

src/missile1.o: src/missile1.cpp.o

.PHONY : src/missile1.o

# target to build an object file
src/missile1.cpp.o:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/missile1.cpp.o
.PHONY : src/missile1.cpp.o

src/missile1.i: src/missile1.cpp.i

.PHONY : src/missile1.i

# target to preprocess a source file
src/missile1.cpp.i:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/missile1.cpp.i
.PHONY : src/missile1.cpp.i

src/missile1.s: src/missile1.cpp.s

.PHONY : src/missile1.s

# target to generate assembly for a file
src/missile1.cpp.s:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/missile1.cpp.s
.PHONY : src/missile1.cpp.s

src/missile2.o: src/missile2.cpp.o

.PHONY : src/missile2.o

# target to build an object file
src/missile2.cpp.o:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/missile2.cpp.o
.PHONY : src/missile2.cpp.o

src/missile2.i: src/missile2.cpp.i

.PHONY : src/missile2.i

# target to preprocess a source file
src/missile2.cpp.i:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/missile2.cpp.i
.PHONY : src/missile2.cpp.i

src/missile2.s: src/missile2.cpp.s

.PHONY : src/missile2.s

# target to generate assembly for a file
src/missile2.cpp.s:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/missile2.cpp.s
.PHONY : src/missile2.cpp.s

src/models.o: src/models.cpp.o

.PHONY : src/models.o

# target to build an object file
src/models.cpp.o:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/models.cpp.o
.PHONY : src/models.cpp.o

src/models.i: src/models.cpp.i

.PHONY : src/models.i

# target to preprocess a source file
src/models.cpp.i:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/models.cpp.i
.PHONY : src/models.cpp.i

src/models.s: src/models.cpp.s

.PHONY : src/models.s

# target to generate assembly for a file
src/models.cpp.s:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/models.cpp.s
.PHONY : src/models.cpp.s

src/nonedit.o: src/nonedit.cpp.o

.PHONY : src/nonedit.o

# target to build an object file
src/nonedit.cpp.o:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/nonedit.cpp.o
.PHONY : src/nonedit.cpp.o

src/nonedit.i: src/nonedit.cpp.i

.PHONY : src/nonedit.i

# target to preprocess a source file
src/nonedit.cpp.i:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/nonedit.cpp.i
.PHONY : src/nonedit.cpp.i

src/nonedit.s: src/nonedit.cpp.s

.PHONY : src/nonedit.s

# target to generate assembly for a file
src/nonedit.cpp.s:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/nonedit.cpp.s
.PHONY : src/nonedit.cpp.s

src/other_handlers.o: src/other_handlers.cpp.o

.PHONY : src/other_handlers.o

# target to build an object file
src/other_handlers.cpp.o:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/other_handlers.cpp.o
.PHONY : src/other_handlers.cpp.o

src/other_handlers.i: src/other_handlers.cpp.i

.PHONY : src/other_handlers.i

# target to preprocess a source file
src/other_handlers.cpp.i:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/other_handlers.cpp.i
.PHONY : src/other_handlers.cpp.i

src/other_handlers.s: src/other_handlers.cpp.s

.PHONY : src/other_handlers.s

# target to generate assembly for a file
src/other_handlers.cpp.s:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/other_handlers.cpp.s
.PHONY : src/other_handlers.cpp.s

src/para.o: src/para.cpp.o

.PHONY : src/para.o

# target to build an object file
src/para.cpp.o:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/para.cpp.o
.PHONY : src/para.cpp.o

src/para.i: src/para.cpp.i

.PHONY : src/para.i

# target to preprocess a source file
src/para.cpp.i:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/para.cpp.i
.PHONY : src/para.cpp.i

src/para.s: src/para.cpp.s

.PHONY : src/para.s

# target to generate assembly for a file
src/para.cpp.s:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/para.cpp.s
.PHONY : src/para.cpp.s

src/plane.o: src/plane.cpp.o

.PHONY : src/plane.o

# target to build an object file
src/plane.cpp.o:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/plane.cpp.o
.PHONY : src/plane.cpp.o

src/plane.i: src/plane.cpp.i

.PHONY : src/plane.i

# target to preprocess a source file
src/plane.cpp.i:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/plane.cpp.i
.PHONY : src/plane.cpp.i

src/plane.s: src/plane.cpp.s

.PHONY : src/plane.s

# target to generate assembly for a file
src/plane.cpp.s:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/plane.cpp.s
.PHONY : src/plane.cpp.s

src/refuel.o: src/refuel.cpp.o

.PHONY : src/refuel.o

# target to build an object file
src/refuel.cpp.o:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/refuel.cpp.o
.PHONY : src/refuel.cpp.o

src/refuel.i: src/refuel.cpp.i

.PHONY : src/refuel.i

# target to preprocess a source file
src/refuel.cpp.i:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/refuel.cpp.i
.PHONY : src/refuel.cpp.i

src/refuel.s: src/refuel.cpp.s

.PHONY : src/refuel.s

# target to generate assembly for a file
src/refuel.cpp.s:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/refuel.cpp.s
.PHONY : src/refuel.cpp.s

src/ring.o: src/ring.cpp.o

.PHONY : src/ring.o

# target to build an object file
src/ring.cpp.o:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/ring.cpp.o
.PHONY : src/ring.cpp.o

src/ring.i: src/ring.cpp.i

.PHONY : src/ring.i

# target to preprocess a source file
src/ring.cpp.i:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/ring.cpp.i
.PHONY : src/ring.cpp.i

src/ring.s: src/ring.cpp.s

.PHONY : src/ring.s

# target to generate assembly for a file
src/ring.cpp.s:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/ring.cpp.s
.PHONY : src/ring.cpp.s

src/sea.o: src/sea.cpp.o

.PHONY : src/sea.o

# target to build an object file
src/sea.cpp.o:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/sea.cpp.o
.PHONY : src/sea.cpp.o

src/sea.i: src/sea.cpp.i

.PHONY : src/sea.i

# target to preprocess a source file
src/sea.cpp.i:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/sea.cpp.i
.PHONY : src/sea.cpp.i

src/sea.s: src/sea.cpp.s

.PHONY : src/sea.s

# target to generate assembly for a file
src/sea.cpp.s:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/sea.cpp.s
.PHONY : src/sea.cpp.s

src/timer.o: src/timer.cpp.o

.PHONY : src/timer.o

# target to build an object file
src/timer.cpp.o:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/timer.cpp.o
.PHONY : src/timer.cpp.o

src/timer.i: src/timer.cpp.i

.PHONY : src/timer.i

# target to preprocess a source file
src/timer.cpp.i:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/timer.cpp.i
.PHONY : src/timer.cpp.i

src/timer.s: src/timer.cpp.s

.PHONY : src/timer.s

# target to generate assembly for a file
src/timer.cpp.s:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/timer.cpp.s
.PHONY : src/timer.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... graphics_asgn1"
	@echo "... edit_cache"
	@echo "... src/airspeed.o"
	@echo "... src/airspeed.i"
	@echo "... src/airspeed.s"
	@echo "... src/altimeter.o"
	@echo "... src/altimeter.i"
	@echo "... src/altimeter.s"
	@echo "... src/ball.o"
	@echo "... src/ball.i"
	@echo "... src/ball.s"
	@echo "... src/bomb.o"
	@echo "... src/bomb.i"
	@echo "... src/bomb.s"
	@echo "... src/color.o"
	@echo "... src/color.i"
	@echo "... src/color.s"
	@echo "... src/enemy.o"
	@echo "... src/enemy.i"
	@echo "... src/enemy.s"
	@echo "... src/enemy_missile.o"
	@echo "... src/enemy_missile.i"
	@echo "... src/enemy_missile.s"
	@echo "... src/fuel_bar.o"
	@echo "... src/fuel_bar.i"
	@echo "... src/fuel_bar.s"
	@echo "... src/input.o"
	@echo "... src/input.i"
	@echo "... src/input.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... src/marker.o"
	@echo "... src/marker.i"
	@echo "... src/marker.s"
	@echo "... src/missile1.o"
	@echo "... src/missile1.i"
	@echo "... src/missile1.s"
	@echo "... src/missile2.o"
	@echo "... src/missile2.i"
	@echo "... src/missile2.s"
	@echo "... src/models.o"
	@echo "... src/models.i"
	@echo "... src/models.s"
	@echo "... src/nonedit.o"
	@echo "... src/nonedit.i"
	@echo "... src/nonedit.s"
	@echo "... src/other_handlers.o"
	@echo "... src/other_handlers.i"
	@echo "... src/other_handlers.s"
	@echo "... src/para.o"
	@echo "... src/para.i"
	@echo "... src/para.s"
	@echo "... src/plane.o"
	@echo "... src/plane.i"
	@echo "... src/plane.s"
	@echo "... src/refuel.o"
	@echo "... src/refuel.i"
	@echo "... src/refuel.s"
	@echo "... src/ring.o"
	@echo "... src/ring.i"
	@echo "... src/ring.s"
	@echo "... src/sea.o"
	@echo "... src/sea.i"
	@echo "... src/sea.s"
	@echo "... src/timer.o"
	@echo "... src/timer.i"
	@echo "... src/timer.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

