# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/david/Escritorio/git-miniGoogle/MiniGoogle/Trie

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/david/Escritorio/git-miniGoogle/MiniGoogle/Trie/build

# Include any dependencies generated for this target.
include CMakeFiles/main_exe.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/main_exe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main_exe.dir/flags.make

CMakeFiles/main_exe.dir/src/wordlist.cpp.o: CMakeFiles/main_exe.dir/flags.make
CMakeFiles/main_exe.dir/src/wordlist.cpp.o: ../src/wordlist.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/david/Escritorio/git-miniGoogle/MiniGoogle/Trie/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main_exe.dir/src/wordlist.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main_exe.dir/src/wordlist.cpp.o -c /home/david/Escritorio/git-miniGoogle/MiniGoogle/Trie/src/wordlist.cpp

CMakeFiles/main_exe.dir/src/wordlist.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main_exe.dir/src/wordlist.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/david/Escritorio/git-miniGoogle/MiniGoogle/Trie/src/wordlist.cpp > CMakeFiles/main_exe.dir/src/wordlist.cpp.i

CMakeFiles/main_exe.dir/src/wordlist.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main_exe.dir/src/wordlist.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/david/Escritorio/git-miniGoogle/MiniGoogle/Trie/src/wordlist.cpp -o CMakeFiles/main_exe.dir/src/wordlist.cpp.s

CMakeFiles/main_exe.dir/src/wordlist.cpp.o.requires:

.PHONY : CMakeFiles/main_exe.dir/src/wordlist.cpp.o.requires

CMakeFiles/main_exe.dir/src/wordlist.cpp.o.provides: CMakeFiles/main_exe.dir/src/wordlist.cpp.o.requires
	$(MAKE) -f CMakeFiles/main_exe.dir/build.make CMakeFiles/main_exe.dir/src/wordlist.cpp.o.provides.build
.PHONY : CMakeFiles/main_exe.dir/src/wordlist.cpp.o.provides

CMakeFiles/main_exe.dir/src/wordlist.cpp.o.provides.build: CMakeFiles/main_exe.dir/src/wordlist.cpp.o


CMakeFiles/main_exe.dir/src/parser.cpp.o: CMakeFiles/main_exe.dir/flags.make
CMakeFiles/main_exe.dir/src/parser.cpp.o: ../src/parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/david/Escritorio/git-miniGoogle/MiniGoogle/Trie/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/main_exe.dir/src/parser.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main_exe.dir/src/parser.cpp.o -c /home/david/Escritorio/git-miniGoogle/MiniGoogle/Trie/src/parser.cpp

CMakeFiles/main_exe.dir/src/parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main_exe.dir/src/parser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/david/Escritorio/git-miniGoogle/MiniGoogle/Trie/src/parser.cpp > CMakeFiles/main_exe.dir/src/parser.cpp.i

CMakeFiles/main_exe.dir/src/parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main_exe.dir/src/parser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/david/Escritorio/git-miniGoogle/MiniGoogle/Trie/src/parser.cpp -o CMakeFiles/main_exe.dir/src/parser.cpp.s

CMakeFiles/main_exe.dir/src/parser.cpp.o.requires:

.PHONY : CMakeFiles/main_exe.dir/src/parser.cpp.o.requires

CMakeFiles/main_exe.dir/src/parser.cpp.o.provides: CMakeFiles/main_exe.dir/src/parser.cpp.o.requires
	$(MAKE) -f CMakeFiles/main_exe.dir/build.make CMakeFiles/main_exe.dir/src/parser.cpp.o.provides.build
.PHONY : CMakeFiles/main_exe.dir/src/parser.cpp.o.provides

CMakeFiles/main_exe.dir/src/parser.cpp.o.provides.build: CMakeFiles/main_exe.dir/src/parser.cpp.o


CMakeFiles/main_exe.dir/src/Node.cpp.o: CMakeFiles/main_exe.dir/flags.make
CMakeFiles/main_exe.dir/src/Node.cpp.o: ../src/Node.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/david/Escritorio/git-miniGoogle/MiniGoogle/Trie/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/main_exe.dir/src/Node.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main_exe.dir/src/Node.cpp.o -c /home/david/Escritorio/git-miniGoogle/MiniGoogle/Trie/src/Node.cpp

CMakeFiles/main_exe.dir/src/Node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main_exe.dir/src/Node.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/david/Escritorio/git-miniGoogle/MiniGoogle/Trie/src/Node.cpp > CMakeFiles/main_exe.dir/src/Node.cpp.i

CMakeFiles/main_exe.dir/src/Node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main_exe.dir/src/Node.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/david/Escritorio/git-miniGoogle/MiniGoogle/Trie/src/Node.cpp -o CMakeFiles/main_exe.dir/src/Node.cpp.s

CMakeFiles/main_exe.dir/src/Node.cpp.o.requires:

.PHONY : CMakeFiles/main_exe.dir/src/Node.cpp.o.requires

CMakeFiles/main_exe.dir/src/Node.cpp.o.provides: CMakeFiles/main_exe.dir/src/Node.cpp.o.requires
	$(MAKE) -f CMakeFiles/main_exe.dir/build.make CMakeFiles/main_exe.dir/src/Node.cpp.o.provides.build
.PHONY : CMakeFiles/main_exe.dir/src/Node.cpp.o.provides

CMakeFiles/main_exe.dir/src/Node.cpp.o.provides.build: CMakeFiles/main_exe.dir/src/Node.cpp.o


CMakeFiles/main_exe.dir/src/Tree.cpp.o: CMakeFiles/main_exe.dir/flags.make
CMakeFiles/main_exe.dir/src/Tree.cpp.o: ../src/Tree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/david/Escritorio/git-miniGoogle/MiniGoogle/Trie/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/main_exe.dir/src/Tree.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main_exe.dir/src/Tree.cpp.o -c /home/david/Escritorio/git-miniGoogle/MiniGoogle/Trie/src/Tree.cpp

CMakeFiles/main_exe.dir/src/Tree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main_exe.dir/src/Tree.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/david/Escritorio/git-miniGoogle/MiniGoogle/Trie/src/Tree.cpp > CMakeFiles/main_exe.dir/src/Tree.cpp.i

CMakeFiles/main_exe.dir/src/Tree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main_exe.dir/src/Tree.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/david/Escritorio/git-miniGoogle/MiniGoogle/Trie/src/Tree.cpp -o CMakeFiles/main_exe.dir/src/Tree.cpp.s

CMakeFiles/main_exe.dir/src/Tree.cpp.o.requires:

.PHONY : CMakeFiles/main_exe.dir/src/Tree.cpp.o.requires

CMakeFiles/main_exe.dir/src/Tree.cpp.o.provides: CMakeFiles/main_exe.dir/src/Tree.cpp.o.requires
	$(MAKE) -f CMakeFiles/main_exe.dir/build.make CMakeFiles/main_exe.dir/src/Tree.cpp.o.provides.build
.PHONY : CMakeFiles/main_exe.dir/src/Tree.cpp.o.provides

CMakeFiles/main_exe.dir/src/Tree.cpp.o.provides.build: CMakeFiles/main_exe.dir/src/Tree.cpp.o


CMakeFiles/main_exe.dir/src/Cloud.cpp.o: CMakeFiles/main_exe.dir/flags.make
CMakeFiles/main_exe.dir/src/Cloud.cpp.o: ../src/Cloud.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/david/Escritorio/git-miniGoogle/MiniGoogle/Trie/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/main_exe.dir/src/Cloud.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main_exe.dir/src/Cloud.cpp.o -c /home/david/Escritorio/git-miniGoogle/MiniGoogle/Trie/src/Cloud.cpp

CMakeFiles/main_exe.dir/src/Cloud.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main_exe.dir/src/Cloud.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/david/Escritorio/git-miniGoogle/MiniGoogle/Trie/src/Cloud.cpp > CMakeFiles/main_exe.dir/src/Cloud.cpp.i

CMakeFiles/main_exe.dir/src/Cloud.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main_exe.dir/src/Cloud.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/david/Escritorio/git-miniGoogle/MiniGoogle/Trie/src/Cloud.cpp -o CMakeFiles/main_exe.dir/src/Cloud.cpp.s

CMakeFiles/main_exe.dir/src/Cloud.cpp.o.requires:

.PHONY : CMakeFiles/main_exe.dir/src/Cloud.cpp.o.requires

CMakeFiles/main_exe.dir/src/Cloud.cpp.o.provides: CMakeFiles/main_exe.dir/src/Cloud.cpp.o.requires
	$(MAKE) -f CMakeFiles/main_exe.dir/build.make CMakeFiles/main_exe.dir/src/Cloud.cpp.o.provides.build
.PHONY : CMakeFiles/main_exe.dir/src/Cloud.cpp.o.provides

CMakeFiles/main_exe.dir/src/Cloud.cpp.o.provides.build: CMakeFiles/main_exe.dir/src/Cloud.cpp.o


CMakeFiles/main_exe.dir/main.cpp.o: CMakeFiles/main_exe.dir/flags.make
CMakeFiles/main_exe.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/david/Escritorio/git-miniGoogle/MiniGoogle/Trie/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/main_exe.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main_exe.dir/main.cpp.o -c /home/david/Escritorio/git-miniGoogle/MiniGoogle/Trie/main.cpp

CMakeFiles/main_exe.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main_exe.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/david/Escritorio/git-miniGoogle/MiniGoogle/Trie/main.cpp > CMakeFiles/main_exe.dir/main.cpp.i

CMakeFiles/main_exe.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main_exe.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/david/Escritorio/git-miniGoogle/MiniGoogle/Trie/main.cpp -o CMakeFiles/main_exe.dir/main.cpp.s

CMakeFiles/main_exe.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/main_exe.dir/main.cpp.o.requires

CMakeFiles/main_exe.dir/main.cpp.o.provides: CMakeFiles/main_exe.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/main_exe.dir/build.make CMakeFiles/main_exe.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/main_exe.dir/main.cpp.o.provides

CMakeFiles/main_exe.dir/main.cpp.o.provides.build: CMakeFiles/main_exe.dir/main.cpp.o


# Object files for target main_exe
main_exe_OBJECTS = \
"CMakeFiles/main_exe.dir/src/wordlist.cpp.o" \
"CMakeFiles/main_exe.dir/src/parser.cpp.o" \
"CMakeFiles/main_exe.dir/src/Node.cpp.o" \
"CMakeFiles/main_exe.dir/src/Tree.cpp.o" \
"CMakeFiles/main_exe.dir/src/Cloud.cpp.o" \
"CMakeFiles/main_exe.dir/main.cpp.o"

# External object files for target main_exe
main_exe_EXTERNAL_OBJECTS =

main_exe: CMakeFiles/main_exe.dir/src/wordlist.cpp.o
main_exe: CMakeFiles/main_exe.dir/src/parser.cpp.o
main_exe: CMakeFiles/main_exe.dir/src/Node.cpp.o
main_exe: CMakeFiles/main_exe.dir/src/Tree.cpp.o
main_exe: CMakeFiles/main_exe.dir/src/Cloud.cpp.o
main_exe: CMakeFiles/main_exe.dir/main.cpp.o
main_exe: CMakeFiles/main_exe.dir/build.make
main_exe: CMakeFiles/main_exe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/david/Escritorio/git-miniGoogle/MiniGoogle/Trie/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable main_exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main_exe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main_exe.dir/build: main_exe

.PHONY : CMakeFiles/main_exe.dir/build

CMakeFiles/main_exe.dir/requires: CMakeFiles/main_exe.dir/src/wordlist.cpp.o.requires
CMakeFiles/main_exe.dir/requires: CMakeFiles/main_exe.dir/src/parser.cpp.o.requires
CMakeFiles/main_exe.dir/requires: CMakeFiles/main_exe.dir/src/Node.cpp.o.requires
CMakeFiles/main_exe.dir/requires: CMakeFiles/main_exe.dir/src/Tree.cpp.o.requires
CMakeFiles/main_exe.dir/requires: CMakeFiles/main_exe.dir/src/Cloud.cpp.o.requires
CMakeFiles/main_exe.dir/requires: CMakeFiles/main_exe.dir/main.cpp.o.requires

.PHONY : CMakeFiles/main_exe.dir/requires

CMakeFiles/main_exe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main_exe.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main_exe.dir/clean

CMakeFiles/main_exe.dir/depend:
	cd /home/david/Escritorio/git-miniGoogle/MiniGoogle/Trie/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/david/Escritorio/git-miniGoogle/MiniGoogle/Trie /home/david/Escritorio/git-miniGoogle/MiniGoogle/Trie /home/david/Escritorio/git-miniGoogle/MiniGoogle/Trie/build /home/david/Escritorio/git-miniGoogle/MiniGoogle/Trie/build /home/david/Escritorio/git-miniGoogle/MiniGoogle/Trie/build/CMakeFiles/main_exe.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main_exe.dir/depend

