# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/michzio/Developer/MyProjects/BachelorDegree/c/common

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/michzio/Developer/MyProjects/BachelorDegree/c/common/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Common_Functions_Lib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Common_Functions_Lib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Common_Functions_Lib.dir/flags.make

CMakeFiles/Common_Functions_Lib.dir/src/strings.c.o: CMakeFiles/Common_Functions_Lib.dir/flags.make
CMakeFiles/Common_Functions_Lib.dir/src/strings.c.o: ../src/strings.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/michzio/Developer/MyProjects/BachelorDegree/c/common/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Common_Functions_Lib.dir/src/strings.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Common_Functions_Lib.dir/src/strings.c.o   -c /Users/michzio/Developer/MyProjects/BachelorDegree/c/common/src/strings.c

CMakeFiles/Common_Functions_Lib.dir/src/strings.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Common_Functions_Lib.dir/src/strings.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/michzio/Developer/MyProjects/BachelorDegree/c/common/src/strings.c > CMakeFiles/Common_Functions_Lib.dir/src/strings.c.i

CMakeFiles/Common_Functions_Lib.dir/src/strings.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Common_Functions_Lib.dir/src/strings.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/michzio/Developer/MyProjects/BachelorDegree/c/common/src/strings.c -o CMakeFiles/Common_Functions_Lib.dir/src/strings.c.s

CMakeFiles/Common_Functions_Lib.dir/src/strings.c.o.requires:

.PHONY : CMakeFiles/Common_Functions_Lib.dir/src/strings.c.o.requires

CMakeFiles/Common_Functions_Lib.dir/src/strings.c.o.provides: CMakeFiles/Common_Functions_Lib.dir/src/strings.c.o.requires
	$(MAKE) -f CMakeFiles/Common_Functions_Lib.dir/build.make CMakeFiles/Common_Functions_Lib.dir/src/strings.c.o.provides.build
.PHONY : CMakeFiles/Common_Functions_Lib.dir/src/strings.c.o.provides

CMakeFiles/Common_Functions_Lib.dir/src/strings.c.o.provides.build: CMakeFiles/Common_Functions_Lib.dir/src/strings.c.o


CMakeFiles/Common_Functions_Lib.dir/src/numbers.c.o: CMakeFiles/Common_Functions_Lib.dir/flags.make
CMakeFiles/Common_Functions_Lib.dir/src/numbers.c.o: ../src/numbers.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/michzio/Developer/MyProjects/BachelorDegree/c/common/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Common_Functions_Lib.dir/src/numbers.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Common_Functions_Lib.dir/src/numbers.c.o   -c /Users/michzio/Developer/MyProjects/BachelorDegree/c/common/src/numbers.c

CMakeFiles/Common_Functions_Lib.dir/src/numbers.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Common_Functions_Lib.dir/src/numbers.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/michzio/Developer/MyProjects/BachelorDegree/c/common/src/numbers.c > CMakeFiles/Common_Functions_Lib.dir/src/numbers.c.i

CMakeFiles/Common_Functions_Lib.dir/src/numbers.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Common_Functions_Lib.dir/src/numbers.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/michzio/Developer/MyProjects/BachelorDegree/c/common/src/numbers.c -o CMakeFiles/Common_Functions_Lib.dir/src/numbers.c.s

CMakeFiles/Common_Functions_Lib.dir/src/numbers.c.o.requires:

.PHONY : CMakeFiles/Common_Functions_Lib.dir/src/numbers.c.o.requires

CMakeFiles/Common_Functions_Lib.dir/src/numbers.c.o.provides: CMakeFiles/Common_Functions_Lib.dir/src/numbers.c.o.requires
	$(MAKE) -f CMakeFiles/Common_Functions_Lib.dir/build.make CMakeFiles/Common_Functions_Lib.dir/src/numbers.c.o.provides.build
.PHONY : CMakeFiles/Common_Functions_Lib.dir/src/numbers.c.o.provides

CMakeFiles/Common_Functions_Lib.dir/src/numbers.c.o.provides.build: CMakeFiles/Common_Functions_Lib.dir/src/numbers.c.o


CMakeFiles/Common_Functions_Lib.dir/src/bitmaps.c.o: CMakeFiles/Common_Functions_Lib.dir/flags.make
CMakeFiles/Common_Functions_Lib.dir/src/bitmaps.c.o: ../src/bitmaps.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/michzio/Developer/MyProjects/BachelorDegree/c/common/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Common_Functions_Lib.dir/src/bitmaps.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Common_Functions_Lib.dir/src/bitmaps.c.o   -c /Users/michzio/Developer/MyProjects/BachelorDegree/c/common/src/bitmaps.c

CMakeFiles/Common_Functions_Lib.dir/src/bitmaps.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Common_Functions_Lib.dir/src/bitmaps.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/michzio/Developer/MyProjects/BachelorDegree/c/common/src/bitmaps.c > CMakeFiles/Common_Functions_Lib.dir/src/bitmaps.c.i

CMakeFiles/Common_Functions_Lib.dir/src/bitmaps.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Common_Functions_Lib.dir/src/bitmaps.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/michzio/Developer/MyProjects/BachelorDegree/c/common/src/bitmaps.c -o CMakeFiles/Common_Functions_Lib.dir/src/bitmaps.c.s

CMakeFiles/Common_Functions_Lib.dir/src/bitmaps.c.o.requires:

.PHONY : CMakeFiles/Common_Functions_Lib.dir/src/bitmaps.c.o.requires

CMakeFiles/Common_Functions_Lib.dir/src/bitmaps.c.o.provides: CMakeFiles/Common_Functions_Lib.dir/src/bitmaps.c.o.requires
	$(MAKE) -f CMakeFiles/Common_Functions_Lib.dir/build.make CMakeFiles/Common_Functions_Lib.dir/src/bitmaps.c.o.provides.build
.PHONY : CMakeFiles/Common_Functions_Lib.dir/src/bitmaps.c.o.provides

CMakeFiles/Common_Functions_Lib.dir/src/bitmaps.c.o.provides.build: CMakeFiles/Common_Functions_Lib.dir/src/bitmaps.c.o


CMakeFiles/Common_Functions_Lib.dir/src/base64.c.o: CMakeFiles/Common_Functions_Lib.dir/flags.make
CMakeFiles/Common_Functions_Lib.dir/src/base64.c.o: ../src/base64.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/michzio/Developer/MyProjects/BachelorDegree/c/common/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/Common_Functions_Lib.dir/src/base64.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Common_Functions_Lib.dir/src/base64.c.o   -c /Users/michzio/Developer/MyProjects/BachelorDegree/c/common/src/base64.c

CMakeFiles/Common_Functions_Lib.dir/src/base64.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Common_Functions_Lib.dir/src/base64.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/michzio/Developer/MyProjects/BachelorDegree/c/common/src/base64.c > CMakeFiles/Common_Functions_Lib.dir/src/base64.c.i

CMakeFiles/Common_Functions_Lib.dir/src/base64.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Common_Functions_Lib.dir/src/base64.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/michzio/Developer/MyProjects/BachelorDegree/c/common/src/base64.c -o CMakeFiles/Common_Functions_Lib.dir/src/base64.c.s

CMakeFiles/Common_Functions_Lib.dir/src/base64.c.o.requires:

.PHONY : CMakeFiles/Common_Functions_Lib.dir/src/base64.c.o.requires

CMakeFiles/Common_Functions_Lib.dir/src/base64.c.o.provides: CMakeFiles/Common_Functions_Lib.dir/src/base64.c.o.requires
	$(MAKE) -f CMakeFiles/Common_Functions_Lib.dir/build.make CMakeFiles/Common_Functions_Lib.dir/src/base64.c.o.provides.build
.PHONY : CMakeFiles/Common_Functions_Lib.dir/src/base64.c.o.provides

CMakeFiles/Common_Functions_Lib.dir/src/base64.c.o.provides.build: CMakeFiles/Common_Functions_Lib.dir/src/base64.c.o


CMakeFiles/Common_Functions_Lib.dir/src/bitwise.c.o: CMakeFiles/Common_Functions_Lib.dir/flags.make
CMakeFiles/Common_Functions_Lib.dir/src/bitwise.c.o: ../src/bitwise.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/michzio/Developer/MyProjects/BachelorDegree/c/common/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/Common_Functions_Lib.dir/src/bitwise.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Common_Functions_Lib.dir/src/bitwise.c.o   -c /Users/michzio/Developer/MyProjects/BachelorDegree/c/common/src/bitwise.c

CMakeFiles/Common_Functions_Lib.dir/src/bitwise.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Common_Functions_Lib.dir/src/bitwise.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/michzio/Developer/MyProjects/BachelorDegree/c/common/src/bitwise.c > CMakeFiles/Common_Functions_Lib.dir/src/bitwise.c.i

CMakeFiles/Common_Functions_Lib.dir/src/bitwise.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Common_Functions_Lib.dir/src/bitwise.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/michzio/Developer/MyProjects/BachelorDegree/c/common/src/bitwise.c -o CMakeFiles/Common_Functions_Lib.dir/src/bitwise.c.s

CMakeFiles/Common_Functions_Lib.dir/src/bitwise.c.o.requires:

.PHONY : CMakeFiles/Common_Functions_Lib.dir/src/bitwise.c.o.requires

CMakeFiles/Common_Functions_Lib.dir/src/bitwise.c.o.provides: CMakeFiles/Common_Functions_Lib.dir/src/bitwise.c.o.requires
	$(MAKE) -f CMakeFiles/Common_Functions_Lib.dir/build.make CMakeFiles/Common_Functions_Lib.dir/src/bitwise.c.o.provides.build
.PHONY : CMakeFiles/Common_Functions_Lib.dir/src/bitwise.c.o.provides

CMakeFiles/Common_Functions_Lib.dir/src/bitwise.c.o.provides.build: CMakeFiles/Common_Functions_Lib.dir/src/bitwise.c.o


CMakeFiles/Common_Functions_Lib.dir/libraries/md5/md5.c.o: CMakeFiles/Common_Functions_Lib.dir/flags.make
CMakeFiles/Common_Functions_Lib.dir/libraries/md5/md5.c.o: ../libraries/md5/md5.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/michzio/Developer/MyProjects/BachelorDegree/c/common/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/Common_Functions_Lib.dir/libraries/md5/md5.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Common_Functions_Lib.dir/libraries/md5/md5.c.o   -c /Users/michzio/Developer/MyProjects/BachelorDegree/c/common/libraries/md5/md5.c

CMakeFiles/Common_Functions_Lib.dir/libraries/md5/md5.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Common_Functions_Lib.dir/libraries/md5/md5.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/michzio/Developer/MyProjects/BachelorDegree/c/common/libraries/md5/md5.c > CMakeFiles/Common_Functions_Lib.dir/libraries/md5/md5.c.i

CMakeFiles/Common_Functions_Lib.dir/libraries/md5/md5.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Common_Functions_Lib.dir/libraries/md5/md5.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/michzio/Developer/MyProjects/BachelorDegree/c/common/libraries/md5/md5.c -o CMakeFiles/Common_Functions_Lib.dir/libraries/md5/md5.c.s

CMakeFiles/Common_Functions_Lib.dir/libraries/md5/md5.c.o.requires:

.PHONY : CMakeFiles/Common_Functions_Lib.dir/libraries/md5/md5.c.o.requires

CMakeFiles/Common_Functions_Lib.dir/libraries/md5/md5.c.o.provides: CMakeFiles/Common_Functions_Lib.dir/libraries/md5/md5.c.o.requires
	$(MAKE) -f CMakeFiles/Common_Functions_Lib.dir/build.make CMakeFiles/Common_Functions_Lib.dir/libraries/md5/md5.c.o.provides.build
.PHONY : CMakeFiles/Common_Functions_Lib.dir/libraries/md5/md5.c.o.provides

CMakeFiles/Common_Functions_Lib.dir/libraries/md5/md5.c.o.provides.build: CMakeFiles/Common_Functions_Lib.dir/libraries/md5/md5.c.o


CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-encoding.c.o: CMakeFiles/Common_Functions_Lib.dir/flags.make
CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-encoding.c.o: ../libraries/png/png-encoding.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/michzio/Developer/MyProjects/BachelorDegree/c/common/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-encoding.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-encoding.c.o   -c /Users/michzio/Developer/MyProjects/BachelorDegree/c/common/libraries/png/png-encoding.c

CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-encoding.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-encoding.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/michzio/Developer/MyProjects/BachelorDegree/c/common/libraries/png/png-encoding.c > CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-encoding.c.i

CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-encoding.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-encoding.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/michzio/Developer/MyProjects/BachelorDegree/c/common/libraries/png/png-encoding.c -o CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-encoding.c.s

CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-encoding.c.o.requires:

.PHONY : CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-encoding.c.o.requires

CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-encoding.c.o.provides: CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-encoding.c.o.requires
	$(MAKE) -f CMakeFiles/Common_Functions_Lib.dir/build.make CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-encoding.c.o.provides.build
.PHONY : CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-encoding.c.o.provides

CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-encoding.c.o.provides.build: CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-encoding.c.o


CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-decoding.c.o: CMakeFiles/Common_Functions_Lib.dir/flags.make
CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-decoding.c.o: ../libraries/png/png-decoding.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/michzio/Developer/MyProjects/BachelorDegree/c/common/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-decoding.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-decoding.c.o   -c /Users/michzio/Developer/MyProjects/BachelorDegree/c/common/libraries/png/png-decoding.c

CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-decoding.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-decoding.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/michzio/Developer/MyProjects/BachelorDegree/c/common/libraries/png/png-decoding.c > CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-decoding.c.i

CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-decoding.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-decoding.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/michzio/Developer/MyProjects/BachelorDegree/c/common/libraries/png/png-decoding.c -o CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-decoding.c.s

CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-decoding.c.o.requires:

.PHONY : CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-decoding.c.o.requires

CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-decoding.c.o.provides: CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-decoding.c.o.requires
	$(MAKE) -f CMakeFiles/Common_Functions_Lib.dir/build.make CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-decoding.c.o.provides.build
.PHONY : CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-decoding.c.o.provides

CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-decoding.c.o.provides.build: CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-decoding.c.o


CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-helper.c.o: CMakeFiles/Common_Functions_Lib.dir/flags.make
CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-helper.c.o: ../libraries/png/png-helper.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/michzio/Developer/MyProjects/BachelorDegree/c/common/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-helper.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-helper.c.o   -c /Users/michzio/Developer/MyProjects/BachelorDegree/c/common/libraries/png/png-helper.c

CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-helper.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-helper.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/michzio/Developer/MyProjects/BachelorDegree/c/common/libraries/png/png-helper.c > CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-helper.c.i

CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-helper.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-helper.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/michzio/Developer/MyProjects/BachelorDegree/c/common/libraries/png/png-helper.c -o CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-helper.c.s

CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-helper.c.o.requires:

.PHONY : CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-helper.c.o.requires

CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-helper.c.o.provides: CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-helper.c.o.requires
	$(MAKE) -f CMakeFiles/Common_Functions_Lib.dir/build.make CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-helper.c.o.provides.build
.PHONY : CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-helper.c.o.provides

CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-helper.c.o.provides.build: CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-helper.c.o


CMakeFiles/Common_Functions_Lib.dir/libraries/lz4/lz4.c.o: CMakeFiles/Common_Functions_Lib.dir/flags.make
CMakeFiles/Common_Functions_Lib.dir/libraries/lz4/lz4.c.o: ../libraries/lz4/lz4.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/michzio/Developer/MyProjects/BachelorDegree/c/common/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/Common_Functions_Lib.dir/libraries/lz4/lz4.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Common_Functions_Lib.dir/libraries/lz4/lz4.c.o   -c /Users/michzio/Developer/MyProjects/BachelorDegree/c/common/libraries/lz4/lz4.c

CMakeFiles/Common_Functions_Lib.dir/libraries/lz4/lz4.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Common_Functions_Lib.dir/libraries/lz4/lz4.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/michzio/Developer/MyProjects/BachelorDegree/c/common/libraries/lz4/lz4.c > CMakeFiles/Common_Functions_Lib.dir/libraries/lz4/lz4.c.i

CMakeFiles/Common_Functions_Lib.dir/libraries/lz4/lz4.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Common_Functions_Lib.dir/libraries/lz4/lz4.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/michzio/Developer/MyProjects/BachelorDegree/c/common/libraries/lz4/lz4.c -o CMakeFiles/Common_Functions_Lib.dir/libraries/lz4/lz4.c.s

CMakeFiles/Common_Functions_Lib.dir/libraries/lz4/lz4.c.o.requires:

.PHONY : CMakeFiles/Common_Functions_Lib.dir/libraries/lz4/lz4.c.o.requires

CMakeFiles/Common_Functions_Lib.dir/libraries/lz4/lz4.c.o.provides: CMakeFiles/Common_Functions_Lib.dir/libraries/lz4/lz4.c.o.requires
	$(MAKE) -f CMakeFiles/Common_Functions_Lib.dir/build.make CMakeFiles/Common_Functions_Lib.dir/libraries/lz4/lz4.c.o.provides.build
.PHONY : CMakeFiles/Common_Functions_Lib.dir/libraries/lz4/lz4.c.o.provides

CMakeFiles/Common_Functions_Lib.dir/libraries/lz4/lz4.c.o.provides.build: CMakeFiles/Common_Functions_Lib.dir/libraries/lz4/lz4.c.o


CMakeFiles/Common_Functions_Lib.dir/src/array_helper.c.o: CMakeFiles/Common_Functions_Lib.dir/flags.make
CMakeFiles/Common_Functions_Lib.dir/src/array_helper.c.o: ../src/array_helper.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/michzio/Developer/MyProjects/BachelorDegree/c/common/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/Common_Functions_Lib.dir/src/array_helper.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Common_Functions_Lib.dir/src/array_helper.c.o   -c /Users/michzio/Developer/MyProjects/BachelorDegree/c/common/src/array_helper.c

CMakeFiles/Common_Functions_Lib.dir/src/array_helper.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Common_Functions_Lib.dir/src/array_helper.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/michzio/Developer/MyProjects/BachelorDegree/c/common/src/array_helper.c > CMakeFiles/Common_Functions_Lib.dir/src/array_helper.c.i

CMakeFiles/Common_Functions_Lib.dir/src/array_helper.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Common_Functions_Lib.dir/src/array_helper.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/michzio/Developer/MyProjects/BachelorDegree/c/common/src/array_helper.c -o CMakeFiles/Common_Functions_Lib.dir/src/array_helper.c.s

CMakeFiles/Common_Functions_Lib.dir/src/array_helper.c.o.requires:

.PHONY : CMakeFiles/Common_Functions_Lib.dir/src/array_helper.c.o.requires

CMakeFiles/Common_Functions_Lib.dir/src/array_helper.c.o.provides: CMakeFiles/Common_Functions_Lib.dir/src/array_helper.c.o.requires
	$(MAKE) -f CMakeFiles/Common_Functions_Lib.dir/build.make CMakeFiles/Common_Functions_Lib.dir/src/array_helper.c.o.provides.build
.PHONY : CMakeFiles/Common_Functions_Lib.dir/src/array_helper.c.o.provides

CMakeFiles/Common_Functions_Lib.dir/src/array_helper.c.o.provides.build: CMakeFiles/Common_Functions_Lib.dir/src/array_helper.c.o


CMakeFiles/Common_Functions_Lib.dir/src/types.c.o: CMakeFiles/Common_Functions_Lib.dir/flags.make
CMakeFiles/Common_Functions_Lib.dir/src/types.c.o: ../src/types.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/michzio/Developer/MyProjects/BachelorDegree/c/common/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object CMakeFiles/Common_Functions_Lib.dir/src/types.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Common_Functions_Lib.dir/src/types.c.o   -c /Users/michzio/Developer/MyProjects/BachelorDegree/c/common/src/types.c

CMakeFiles/Common_Functions_Lib.dir/src/types.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Common_Functions_Lib.dir/src/types.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/michzio/Developer/MyProjects/BachelorDegree/c/common/src/types.c > CMakeFiles/Common_Functions_Lib.dir/src/types.c.i

CMakeFiles/Common_Functions_Lib.dir/src/types.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Common_Functions_Lib.dir/src/types.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/michzio/Developer/MyProjects/BachelorDegree/c/common/src/types.c -o CMakeFiles/Common_Functions_Lib.dir/src/types.c.s

CMakeFiles/Common_Functions_Lib.dir/src/types.c.o.requires:

.PHONY : CMakeFiles/Common_Functions_Lib.dir/src/types.c.o.requires

CMakeFiles/Common_Functions_Lib.dir/src/types.c.o.provides: CMakeFiles/Common_Functions_Lib.dir/src/types.c.o.requires
	$(MAKE) -f CMakeFiles/Common_Functions_Lib.dir/build.make CMakeFiles/Common_Functions_Lib.dir/src/types.c.o.provides.build
.PHONY : CMakeFiles/Common_Functions_Lib.dir/src/types.c.o.provides

CMakeFiles/Common_Functions_Lib.dir/src/types.c.o.provides.build: CMakeFiles/Common_Functions_Lib.dir/src/types.c.o


CMakeFiles/Common_Functions_Lib.dir/src/system.c.o: CMakeFiles/Common_Functions_Lib.dir/flags.make
CMakeFiles/Common_Functions_Lib.dir/src/system.c.o: ../src/system.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/michzio/Developer/MyProjects/BachelorDegree/c/common/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building C object CMakeFiles/Common_Functions_Lib.dir/src/system.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Common_Functions_Lib.dir/src/system.c.o   -c /Users/michzio/Developer/MyProjects/BachelorDegree/c/common/src/system.c

CMakeFiles/Common_Functions_Lib.dir/src/system.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Common_Functions_Lib.dir/src/system.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/michzio/Developer/MyProjects/BachelorDegree/c/common/src/system.c > CMakeFiles/Common_Functions_Lib.dir/src/system.c.i

CMakeFiles/Common_Functions_Lib.dir/src/system.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Common_Functions_Lib.dir/src/system.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/michzio/Developer/MyProjects/BachelorDegree/c/common/src/system.c -o CMakeFiles/Common_Functions_Lib.dir/src/system.c.s

CMakeFiles/Common_Functions_Lib.dir/src/system.c.o.requires:

.PHONY : CMakeFiles/Common_Functions_Lib.dir/src/system.c.o.requires

CMakeFiles/Common_Functions_Lib.dir/src/system.c.o.provides: CMakeFiles/Common_Functions_Lib.dir/src/system.c.o.requires
	$(MAKE) -f CMakeFiles/Common_Functions_Lib.dir/build.make CMakeFiles/Common_Functions_Lib.dir/src/system.c.o.provides.build
.PHONY : CMakeFiles/Common_Functions_Lib.dir/src/system.c.o.provides

CMakeFiles/Common_Functions_Lib.dir/src/system.c.o.provides.build: CMakeFiles/Common_Functions_Lib.dir/src/system.c.o


# Object files for target Common_Functions_Lib
Common_Functions_Lib_OBJECTS = \
"CMakeFiles/Common_Functions_Lib.dir/src/strings.c.o" \
"CMakeFiles/Common_Functions_Lib.dir/src/numbers.c.o" \
"CMakeFiles/Common_Functions_Lib.dir/src/bitmaps.c.o" \
"CMakeFiles/Common_Functions_Lib.dir/src/base64.c.o" \
"CMakeFiles/Common_Functions_Lib.dir/src/bitwise.c.o" \
"CMakeFiles/Common_Functions_Lib.dir/libraries/md5/md5.c.o" \
"CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-encoding.c.o" \
"CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-decoding.c.o" \
"CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-helper.c.o" \
"CMakeFiles/Common_Functions_Lib.dir/libraries/lz4/lz4.c.o" \
"CMakeFiles/Common_Functions_Lib.dir/src/array_helper.c.o" \
"CMakeFiles/Common_Functions_Lib.dir/src/types.c.o" \
"CMakeFiles/Common_Functions_Lib.dir/src/system.c.o"

# External object files for target Common_Functions_Lib
Common_Functions_Lib_EXTERNAL_OBJECTS =

../outputs/lib/apple/libcommon_functions.dylib: CMakeFiles/Common_Functions_Lib.dir/src/strings.c.o
../outputs/lib/apple/libcommon_functions.dylib: CMakeFiles/Common_Functions_Lib.dir/src/numbers.c.o
../outputs/lib/apple/libcommon_functions.dylib: CMakeFiles/Common_Functions_Lib.dir/src/bitmaps.c.o
../outputs/lib/apple/libcommon_functions.dylib: CMakeFiles/Common_Functions_Lib.dir/src/base64.c.o
../outputs/lib/apple/libcommon_functions.dylib: CMakeFiles/Common_Functions_Lib.dir/src/bitwise.c.o
../outputs/lib/apple/libcommon_functions.dylib: CMakeFiles/Common_Functions_Lib.dir/libraries/md5/md5.c.o
../outputs/lib/apple/libcommon_functions.dylib: CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-encoding.c.o
../outputs/lib/apple/libcommon_functions.dylib: CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-decoding.c.o
../outputs/lib/apple/libcommon_functions.dylib: CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-helper.c.o
../outputs/lib/apple/libcommon_functions.dylib: CMakeFiles/Common_Functions_Lib.dir/libraries/lz4/lz4.c.o
../outputs/lib/apple/libcommon_functions.dylib: CMakeFiles/Common_Functions_Lib.dir/src/array_helper.c.o
../outputs/lib/apple/libcommon_functions.dylib: CMakeFiles/Common_Functions_Lib.dir/src/types.c.o
../outputs/lib/apple/libcommon_functions.dylib: CMakeFiles/Common_Functions_Lib.dir/src/system.c.o
../outputs/lib/apple/libcommon_functions.dylib: CMakeFiles/Common_Functions_Lib.dir/build.make
../outputs/lib/apple/libcommon_functions.dylib: /usr/local/lib/libopencv_highgui.2.4.13.dylib
../outputs/lib/apple/libcommon_functions.dylib: /Users/michzio/Developer/MyProjects/BachelorDegree/c/libpng-1.6.24/outputs/lib/apple/liblibpng.dylib
../outputs/lib/apple/libcommon_functions.dylib: /usr/local/lib/libopencv_imgproc.2.4.13.dylib
../outputs/lib/apple/libcommon_functions.dylib: /usr/local/lib/libopencv_core.2.4.13.dylib
../outputs/lib/apple/libcommon_functions.dylib: /Users/michzio/Developer/MyProjects/BachelorDegree/c/zlib-1.2.8/outputs/lib/apple/libzlib.dylib
../outputs/lib/apple/libcommon_functions.dylib: CMakeFiles/Common_Functions_Lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/michzio/Developer/MyProjects/BachelorDegree/c/common/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Linking C shared library ../outputs/lib/apple/libcommon_functions.dylib"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Common_Functions_Lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Common_Functions_Lib.dir/build: ../outputs/lib/apple/libcommon_functions.dylib

.PHONY : CMakeFiles/Common_Functions_Lib.dir/build

CMakeFiles/Common_Functions_Lib.dir/requires: CMakeFiles/Common_Functions_Lib.dir/src/strings.c.o.requires
CMakeFiles/Common_Functions_Lib.dir/requires: CMakeFiles/Common_Functions_Lib.dir/src/numbers.c.o.requires
CMakeFiles/Common_Functions_Lib.dir/requires: CMakeFiles/Common_Functions_Lib.dir/src/bitmaps.c.o.requires
CMakeFiles/Common_Functions_Lib.dir/requires: CMakeFiles/Common_Functions_Lib.dir/src/base64.c.o.requires
CMakeFiles/Common_Functions_Lib.dir/requires: CMakeFiles/Common_Functions_Lib.dir/src/bitwise.c.o.requires
CMakeFiles/Common_Functions_Lib.dir/requires: CMakeFiles/Common_Functions_Lib.dir/libraries/md5/md5.c.o.requires
CMakeFiles/Common_Functions_Lib.dir/requires: CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-encoding.c.o.requires
CMakeFiles/Common_Functions_Lib.dir/requires: CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-decoding.c.o.requires
CMakeFiles/Common_Functions_Lib.dir/requires: CMakeFiles/Common_Functions_Lib.dir/libraries/png/png-helper.c.o.requires
CMakeFiles/Common_Functions_Lib.dir/requires: CMakeFiles/Common_Functions_Lib.dir/libraries/lz4/lz4.c.o.requires
CMakeFiles/Common_Functions_Lib.dir/requires: CMakeFiles/Common_Functions_Lib.dir/src/array_helper.c.o.requires
CMakeFiles/Common_Functions_Lib.dir/requires: CMakeFiles/Common_Functions_Lib.dir/src/types.c.o.requires
CMakeFiles/Common_Functions_Lib.dir/requires: CMakeFiles/Common_Functions_Lib.dir/src/system.c.o.requires

.PHONY : CMakeFiles/Common_Functions_Lib.dir/requires

CMakeFiles/Common_Functions_Lib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Common_Functions_Lib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Common_Functions_Lib.dir/clean

CMakeFiles/Common_Functions_Lib.dir/depend:
	cd /Users/michzio/Developer/MyProjects/BachelorDegree/c/common/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/michzio/Developer/MyProjects/BachelorDegree/c/common /Users/michzio/Developer/MyProjects/BachelorDegree/c/common /Users/michzio/Developer/MyProjects/BachelorDegree/c/common/cmake-build-debug /Users/michzio/Developer/MyProjects/BachelorDegree/c/common/cmake-build-debug /Users/michzio/Developer/MyProjects/BachelorDegree/c/common/cmake-build-debug/CMakeFiles/Common_Functions_Lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Common_Functions_Lib.dir/depend

