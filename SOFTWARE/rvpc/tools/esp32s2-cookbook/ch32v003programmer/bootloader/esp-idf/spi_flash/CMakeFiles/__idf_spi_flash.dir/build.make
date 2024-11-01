# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kalata23/github/esp-idf_5_1/esp-idf/components/bootloader/subproject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kalata23/github/esp32s2-cookbook/ch32v003programmer/bootloader

# Include any dependencies generated for this target.
include esp-idf/spi_flash/CMakeFiles/__idf_spi_flash.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include esp-idf/spi_flash/CMakeFiles/__idf_spi_flash.dir/compiler_depend.make

# Include the progress variables for this target.
include esp-idf/spi_flash/CMakeFiles/__idf_spi_flash.dir/progress.make

# Include the compile flags for this target's objects.
include esp-idf/spi_flash/CMakeFiles/__idf_spi_flash.dir/flags.make

esp-idf/spi_flash/CMakeFiles/__idf_spi_flash.dir/spi_flash_wrap.c.obj: esp-idf/spi_flash/CMakeFiles/__idf_spi_flash.dir/flags.make
esp-idf/spi_flash/CMakeFiles/__idf_spi_flash.dir/spi_flash_wrap.c.obj: /home/kalata23/github/esp-idf_5_1/esp-idf/components/spi_flash/spi_flash_wrap.c
esp-idf/spi_flash/CMakeFiles/__idf_spi_flash.dir/spi_flash_wrap.c.obj: esp-idf/spi_flash/CMakeFiles/__idf_spi_flash.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kalata23/github/esp32s2-cookbook/ch32v003programmer/bootloader/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object esp-idf/spi_flash/CMakeFiles/__idf_spi_flash.dir/spi_flash_wrap.c.obj"
	cd /home/kalata23/github/esp32s2-cookbook/ch32v003programmer/bootloader/esp-idf/spi_flash && /home/kalata23/.espressif/tools/xtensa-esp32s2-elf/esp-12.2.0_20230208/xtensa-esp32s2-elf/bin/xtensa-esp32s2-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT esp-idf/spi_flash/CMakeFiles/__idf_spi_flash.dir/spi_flash_wrap.c.obj -MF CMakeFiles/__idf_spi_flash.dir/spi_flash_wrap.c.obj.d -o CMakeFiles/__idf_spi_flash.dir/spi_flash_wrap.c.obj -c /home/kalata23/github/esp-idf_5_1/esp-idf/components/spi_flash/spi_flash_wrap.c

esp-idf/spi_flash/CMakeFiles/__idf_spi_flash.dir/spi_flash_wrap.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/__idf_spi_flash.dir/spi_flash_wrap.c.i"
	cd /home/kalata23/github/esp32s2-cookbook/ch32v003programmer/bootloader/esp-idf/spi_flash && /home/kalata23/.espressif/tools/xtensa-esp32s2-elf/esp-12.2.0_20230208/xtensa-esp32s2-elf/bin/xtensa-esp32s2-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kalata23/github/esp-idf_5_1/esp-idf/components/spi_flash/spi_flash_wrap.c > CMakeFiles/__idf_spi_flash.dir/spi_flash_wrap.c.i

esp-idf/spi_flash/CMakeFiles/__idf_spi_flash.dir/spi_flash_wrap.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/__idf_spi_flash.dir/spi_flash_wrap.c.s"
	cd /home/kalata23/github/esp32s2-cookbook/ch32v003programmer/bootloader/esp-idf/spi_flash && /home/kalata23/.espressif/tools/xtensa-esp32s2-elf/esp-12.2.0_20230208/xtensa-esp32s2-elf/bin/xtensa-esp32s2-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kalata23/github/esp-idf_5_1/esp-idf/components/spi_flash/spi_flash_wrap.c -o CMakeFiles/__idf_spi_flash.dir/spi_flash_wrap.c.s

# Object files for target __idf_spi_flash
__idf_spi_flash_OBJECTS = \
"CMakeFiles/__idf_spi_flash.dir/spi_flash_wrap.c.obj"

# External object files for target __idf_spi_flash
__idf_spi_flash_EXTERNAL_OBJECTS =

esp-idf/spi_flash/libspi_flash.a: esp-idf/spi_flash/CMakeFiles/__idf_spi_flash.dir/spi_flash_wrap.c.obj
esp-idf/spi_flash/libspi_flash.a: esp-idf/spi_flash/CMakeFiles/__idf_spi_flash.dir/build.make
esp-idf/spi_flash/libspi_flash.a: esp-idf/spi_flash/CMakeFiles/__idf_spi_flash.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kalata23/github/esp32s2-cookbook/ch32v003programmer/bootloader/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libspi_flash.a"
	cd /home/kalata23/github/esp32s2-cookbook/ch32v003programmer/bootloader/esp-idf/spi_flash && $(CMAKE_COMMAND) -P CMakeFiles/__idf_spi_flash.dir/cmake_clean_target.cmake
	cd /home/kalata23/github/esp32s2-cookbook/ch32v003programmer/bootloader/esp-idf/spi_flash && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/__idf_spi_flash.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
esp-idf/spi_flash/CMakeFiles/__idf_spi_flash.dir/build: esp-idf/spi_flash/libspi_flash.a
.PHONY : esp-idf/spi_flash/CMakeFiles/__idf_spi_flash.dir/build

esp-idf/spi_flash/CMakeFiles/__idf_spi_flash.dir/clean:
	cd /home/kalata23/github/esp32s2-cookbook/ch32v003programmer/bootloader/esp-idf/spi_flash && $(CMAKE_COMMAND) -P CMakeFiles/__idf_spi_flash.dir/cmake_clean.cmake
.PHONY : esp-idf/spi_flash/CMakeFiles/__idf_spi_flash.dir/clean

esp-idf/spi_flash/CMakeFiles/__idf_spi_flash.dir/depend:
	cd /home/kalata23/github/esp32s2-cookbook/ch32v003programmer/bootloader && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kalata23/github/esp-idf_5_1/esp-idf/components/bootloader/subproject /home/kalata23/github/esp-idf_5_1/esp-idf/components/spi_flash /home/kalata23/github/esp32s2-cookbook/ch32v003programmer/bootloader /home/kalata23/github/esp32s2-cookbook/ch32v003programmer/bootloader/esp-idf/spi_flash /home/kalata23/github/esp32s2-cookbook/ch32v003programmer/bootloader/esp-idf/spi_flash/CMakeFiles/__idf_spi_flash.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : esp-idf/spi_flash/CMakeFiles/__idf_spi_flash.dir/depend
