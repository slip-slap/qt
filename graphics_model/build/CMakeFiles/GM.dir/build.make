# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /opt/local/bin/cmake

# The command to remove a file.
RM = /opt/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/kismet/Desktop/qt/stock

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/kismet/Desktop/qt/stock/build

# Include any dependencies generated for this target.
include CMakeFiles/GM.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/GM.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GM.dir/flags.make

qrc_resource.cpp: ../resource/img/new.svg
qrc_resource.cpp: ../resource/img/folder.svg
qrc_resource.cpp: ../resource/img/zoomin.png
qrc_resource.cpp: ../resource/img/zoomout.png
qrc_resource.cpp: resource.qrc.depends
qrc_resource.cpp: ../resource.qrc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/kismet/Desktop/qt/stock/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating qrc_resource.cpp"
	/usr/local/Cellar/qt@5/5.15.2/bin/rcc --name resource --output /Users/kismet/Desktop/qt/stock/build/qrc_resource.cpp /Users/kismet/Desktop/qt/stock/resource.qrc

CMakeFiles/GM.dir/GM_autogen/mocs_compilation.cpp.o: CMakeFiles/GM.dir/flags.make
CMakeFiles/GM.dir/GM_autogen/mocs_compilation.cpp.o: GM_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kismet/Desktop/qt/stock/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/GM.dir/GM_autogen/mocs_compilation.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GM.dir/GM_autogen/mocs_compilation.cpp.o -c /Users/kismet/Desktop/qt/stock/build/GM_autogen/mocs_compilation.cpp

CMakeFiles/GM.dir/GM_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GM.dir/GM_autogen/mocs_compilation.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kismet/Desktop/qt/stock/build/GM_autogen/mocs_compilation.cpp > CMakeFiles/GM.dir/GM_autogen/mocs_compilation.cpp.i

CMakeFiles/GM.dir/GM_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GM.dir/GM_autogen/mocs_compilation.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kismet/Desktop/qt/stock/build/GM_autogen/mocs_compilation.cpp -o CMakeFiles/GM.dir/GM_autogen/mocs_compilation.cpp.s

CMakeFiles/GM.dir/src/main.cpp.o: CMakeFiles/GM.dir/flags.make
CMakeFiles/GM.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kismet/Desktop/qt/stock/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/GM.dir/src/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GM.dir/src/main.cpp.o -c /Users/kismet/Desktop/qt/stock/src/main.cpp

CMakeFiles/GM.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GM.dir/src/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kismet/Desktop/qt/stock/src/main.cpp > CMakeFiles/GM.dir/src/main.cpp.i

CMakeFiles/GM.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GM.dir/src/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kismet/Desktop/qt/stock/src/main.cpp -o CMakeFiles/GM.dir/src/main.cpp.s

CMakeFiles/GM.dir/src/mainwindow.cpp.o: CMakeFiles/GM.dir/flags.make
CMakeFiles/GM.dir/src/mainwindow.cpp.o: ../src/mainwindow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kismet/Desktop/qt/stock/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/GM.dir/src/mainwindow.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GM.dir/src/mainwindow.cpp.o -c /Users/kismet/Desktop/qt/stock/src/mainwindow.cpp

CMakeFiles/GM.dir/src/mainwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GM.dir/src/mainwindow.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kismet/Desktop/qt/stock/src/mainwindow.cpp > CMakeFiles/GM.dir/src/mainwindow.cpp.i

CMakeFiles/GM.dir/src/mainwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GM.dir/src/mainwindow.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kismet/Desktop/qt/stock/src/mainwindow.cpp -o CMakeFiles/GM.dir/src/mainwindow.cpp.s

CMakeFiles/GM.dir/src/gmgraphicsview.cpp.o: CMakeFiles/GM.dir/flags.make
CMakeFiles/GM.dir/src/gmgraphicsview.cpp.o: ../src/gmgraphicsview.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kismet/Desktop/qt/stock/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/GM.dir/src/gmgraphicsview.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GM.dir/src/gmgraphicsview.cpp.o -c /Users/kismet/Desktop/qt/stock/src/gmgraphicsview.cpp

CMakeFiles/GM.dir/src/gmgraphicsview.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GM.dir/src/gmgraphicsview.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kismet/Desktop/qt/stock/src/gmgraphicsview.cpp > CMakeFiles/GM.dir/src/gmgraphicsview.cpp.i

CMakeFiles/GM.dir/src/gmgraphicsview.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GM.dir/src/gmgraphicsview.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kismet/Desktop/qt/stock/src/gmgraphicsview.cpp -o CMakeFiles/GM.dir/src/gmgraphicsview.cpp.s

CMakeFiles/GM.dir/src/gmscene.cpp.o: CMakeFiles/GM.dir/flags.make
CMakeFiles/GM.dir/src/gmscene.cpp.o: ../src/gmscene.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kismet/Desktop/qt/stock/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/GM.dir/src/gmscene.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GM.dir/src/gmscene.cpp.o -c /Users/kismet/Desktop/qt/stock/src/gmscene.cpp

CMakeFiles/GM.dir/src/gmscene.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GM.dir/src/gmscene.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kismet/Desktop/qt/stock/src/gmscene.cpp > CMakeFiles/GM.dir/src/gmscene.cpp.i

CMakeFiles/GM.dir/src/gmscene.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GM.dir/src/gmscene.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kismet/Desktop/qt/stock/src/gmscene.cpp -o CMakeFiles/GM.dir/src/gmscene.cpp.s

CMakeFiles/GM.dir/src/gmnode.cpp.o: CMakeFiles/GM.dir/flags.make
CMakeFiles/GM.dir/src/gmnode.cpp.o: ../src/gmnode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kismet/Desktop/qt/stock/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/GM.dir/src/gmnode.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GM.dir/src/gmnode.cpp.o -c /Users/kismet/Desktop/qt/stock/src/gmnode.cpp

CMakeFiles/GM.dir/src/gmnode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GM.dir/src/gmnode.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kismet/Desktop/qt/stock/src/gmnode.cpp > CMakeFiles/GM.dir/src/gmnode.cpp.i

CMakeFiles/GM.dir/src/gmnode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GM.dir/src/gmnode.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kismet/Desktop/qt/stock/src/gmnode.cpp -o CMakeFiles/GM.dir/src/gmnode.cpp.s

CMakeFiles/GM.dir/src/gmedge.cpp.o: CMakeFiles/GM.dir/flags.make
CMakeFiles/GM.dir/src/gmedge.cpp.o: ../src/gmedge.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kismet/Desktop/qt/stock/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/GM.dir/src/gmedge.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GM.dir/src/gmedge.cpp.o -c /Users/kismet/Desktop/qt/stock/src/gmedge.cpp

CMakeFiles/GM.dir/src/gmedge.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GM.dir/src/gmedge.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kismet/Desktop/qt/stock/src/gmedge.cpp > CMakeFiles/GM.dir/src/gmedge.cpp.i

CMakeFiles/GM.dir/src/gmedge.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GM.dir/src/gmedge.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kismet/Desktop/qt/stock/src/gmedge.cpp -o CMakeFiles/GM.dir/src/gmedge.cpp.s

CMakeFiles/GM.dir/src/gmsocket.cpp.o: CMakeFiles/GM.dir/flags.make
CMakeFiles/GM.dir/src/gmsocket.cpp.o: ../src/gmsocket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kismet/Desktop/qt/stock/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/GM.dir/src/gmsocket.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GM.dir/src/gmsocket.cpp.o -c /Users/kismet/Desktop/qt/stock/src/gmsocket.cpp

CMakeFiles/GM.dir/src/gmsocket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GM.dir/src/gmsocket.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kismet/Desktop/qt/stock/src/gmsocket.cpp > CMakeFiles/GM.dir/src/gmsocket.cpp.i

CMakeFiles/GM.dir/src/gmsocket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GM.dir/src/gmsocket.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kismet/Desktop/qt/stock/src/gmsocket.cpp -o CMakeFiles/GM.dir/src/gmsocket.cpp.s

CMakeFiles/GM.dir/src/gmqtgraphicssocket.cpp.o: CMakeFiles/GM.dir/flags.make
CMakeFiles/GM.dir/src/gmqtgraphicssocket.cpp.o: ../src/gmqtgraphicssocket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kismet/Desktop/qt/stock/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/GM.dir/src/gmqtgraphicssocket.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GM.dir/src/gmqtgraphicssocket.cpp.o -c /Users/kismet/Desktop/qt/stock/src/gmqtgraphicssocket.cpp

CMakeFiles/GM.dir/src/gmqtgraphicssocket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GM.dir/src/gmqtgraphicssocket.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kismet/Desktop/qt/stock/src/gmqtgraphicssocket.cpp > CMakeFiles/GM.dir/src/gmqtgraphicssocket.cpp.i

CMakeFiles/GM.dir/src/gmqtgraphicssocket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GM.dir/src/gmqtgraphicssocket.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kismet/Desktop/qt/stock/src/gmqtgraphicssocket.cpp -o CMakeFiles/GM.dir/src/gmqtgraphicssocket.cpp.s

CMakeFiles/GM.dir/src/gmqtgraphicsscene.cpp.o: CMakeFiles/GM.dir/flags.make
CMakeFiles/GM.dir/src/gmqtgraphicsscene.cpp.o: ../src/gmqtgraphicsscene.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kismet/Desktop/qt/stock/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/GM.dir/src/gmqtgraphicsscene.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GM.dir/src/gmqtgraphicsscene.cpp.o -c /Users/kismet/Desktop/qt/stock/src/gmqtgraphicsscene.cpp

CMakeFiles/GM.dir/src/gmqtgraphicsscene.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GM.dir/src/gmqtgraphicsscene.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kismet/Desktop/qt/stock/src/gmqtgraphicsscene.cpp > CMakeFiles/GM.dir/src/gmqtgraphicsscene.cpp.i

CMakeFiles/GM.dir/src/gmqtgraphicsscene.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GM.dir/src/gmqtgraphicsscene.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kismet/Desktop/qt/stock/src/gmqtgraphicsscene.cpp -o CMakeFiles/GM.dir/src/gmqtgraphicsscene.cpp.s

CMakeFiles/GM.dir/src/gmqtgraphicsnode.cpp.o: CMakeFiles/GM.dir/flags.make
CMakeFiles/GM.dir/src/gmqtgraphicsnode.cpp.o: ../src/gmqtgraphicsnode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kismet/Desktop/qt/stock/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/GM.dir/src/gmqtgraphicsnode.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GM.dir/src/gmqtgraphicsnode.cpp.o -c /Users/kismet/Desktop/qt/stock/src/gmqtgraphicsnode.cpp

CMakeFiles/GM.dir/src/gmqtgraphicsnode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GM.dir/src/gmqtgraphicsnode.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kismet/Desktop/qt/stock/src/gmqtgraphicsnode.cpp > CMakeFiles/GM.dir/src/gmqtgraphicsnode.cpp.i

CMakeFiles/GM.dir/src/gmqtgraphicsnode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GM.dir/src/gmqtgraphicsnode.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kismet/Desktop/qt/stock/src/gmqtgraphicsnode.cpp -o CMakeFiles/GM.dir/src/gmqtgraphicsnode.cpp.s

CMakeFiles/GM.dir/src/gmqtgraphicsedge.cpp.o: CMakeFiles/GM.dir/flags.make
CMakeFiles/GM.dir/src/gmqtgraphicsedge.cpp.o: ../src/gmqtgraphicsedge.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kismet/Desktop/qt/stock/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/GM.dir/src/gmqtgraphicsedge.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GM.dir/src/gmqtgraphicsedge.cpp.o -c /Users/kismet/Desktop/qt/stock/src/gmqtgraphicsedge.cpp

CMakeFiles/GM.dir/src/gmqtgraphicsedge.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GM.dir/src/gmqtgraphicsedge.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kismet/Desktop/qt/stock/src/gmqtgraphicsedge.cpp > CMakeFiles/GM.dir/src/gmqtgraphicsedge.cpp.i

CMakeFiles/GM.dir/src/gmqtgraphicsedge.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GM.dir/src/gmqtgraphicsedge.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kismet/Desktop/qt/stock/src/gmqtgraphicsedge.cpp -o CMakeFiles/GM.dir/src/gmqtgraphicsedge.cpp.s

CMakeFiles/GM.dir/src/gmqtgraphicscuttingline.cpp.o: CMakeFiles/GM.dir/flags.make
CMakeFiles/GM.dir/src/gmqtgraphicscuttingline.cpp.o: ../src/gmqtgraphicscuttingline.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kismet/Desktop/qt/stock/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/GM.dir/src/gmqtgraphicscuttingline.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GM.dir/src/gmqtgraphicscuttingline.cpp.o -c /Users/kismet/Desktop/qt/stock/src/gmqtgraphicscuttingline.cpp

CMakeFiles/GM.dir/src/gmqtgraphicscuttingline.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GM.dir/src/gmqtgraphicscuttingline.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kismet/Desktop/qt/stock/src/gmqtgraphicscuttingline.cpp > CMakeFiles/GM.dir/src/gmqtgraphicscuttingline.cpp.i

CMakeFiles/GM.dir/src/gmqtgraphicscuttingline.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GM.dir/src/gmqtgraphicscuttingline.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kismet/Desktop/qt/stock/src/gmqtgraphicscuttingline.cpp -o CMakeFiles/GM.dir/src/gmqtgraphicscuttingline.cpp.s

CMakeFiles/GM.dir/qrc_resource.cpp.o: CMakeFiles/GM.dir/flags.make
CMakeFiles/GM.dir/qrc_resource.cpp.o: qrc_resource.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kismet/Desktop/qt/stock/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/GM.dir/qrc_resource.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GM.dir/qrc_resource.cpp.o -c /Users/kismet/Desktop/qt/stock/build/qrc_resource.cpp

CMakeFiles/GM.dir/qrc_resource.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GM.dir/qrc_resource.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kismet/Desktop/qt/stock/build/qrc_resource.cpp > CMakeFiles/GM.dir/qrc_resource.cpp.i

CMakeFiles/GM.dir/qrc_resource.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GM.dir/qrc_resource.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kismet/Desktop/qt/stock/build/qrc_resource.cpp -o CMakeFiles/GM.dir/qrc_resource.cpp.s

# Object files for target GM
GM_OBJECTS = \
"CMakeFiles/GM.dir/GM_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/GM.dir/src/main.cpp.o" \
"CMakeFiles/GM.dir/src/mainwindow.cpp.o" \
"CMakeFiles/GM.dir/src/gmgraphicsview.cpp.o" \
"CMakeFiles/GM.dir/src/gmscene.cpp.o" \
"CMakeFiles/GM.dir/src/gmnode.cpp.o" \
"CMakeFiles/GM.dir/src/gmedge.cpp.o" \
"CMakeFiles/GM.dir/src/gmsocket.cpp.o" \
"CMakeFiles/GM.dir/src/gmqtgraphicssocket.cpp.o" \
"CMakeFiles/GM.dir/src/gmqtgraphicsscene.cpp.o" \
"CMakeFiles/GM.dir/src/gmqtgraphicsnode.cpp.o" \
"CMakeFiles/GM.dir/src/gmqtgraphicsedge.cpp.o" \
"CMakeFiles/GM.dir/src/gmqtgraphicscuttingline.cpp.o" \
"CMakeFiles/GM.dir/qrc_resource.cpp.o"

# External object files for target GM
GM_EXTERNAL_OBJECTS =

GM: CMakeFiles/GM.dir/GM_autogen/mocs_compilation.cpp.o
GM: CMakeFiles/GM.dir/src/main.cpp.o
GM: CMakeFiles/GM.dir/src/mainwindow.cpp.o
GM: CMakeFiles/GM.dir/src/gmgraphicsview.cpp.o
GM: CMakeFiles/GM.dir/src/gmscene.cpp.o
GM: CMakeFiles/GM.dir/src/gmnode.cpp.o
GM: CMakeFiles/GM.dir/src/gmedge.cpp.o
GM: CMakeFiles/GM.dir/src/gmsocket.cpp.o
GM: CMakeFiles/GM.dir/src/gmqtgraphicssocket.cpp.o
GM: CMakeFiles/GM.dir/src/gmqtgraphicsscene.cpp.o
GM: CMakeFiles/GM.dir/src/gmqtgraphicsnode.cpp.o
GM: CMakeFiles/GM.dir/src/gmqtgraphicsedge.cpp.o
GM: CMakeFiles/GM.dir/src/gmqtgraphicscuttingline.cpp.o
GM: CMakeFiles/GM.dir/qrc_resource.cpp.o
GM: CMakeFiles/GM.dir/build.make
GM: /usr/local/Cellar/qt@5/5.15.2/lib/QtWidgets.framework/QtWidgets
GM: /usr/local/Cellar/qt@5/5.15.2/lib/QtGui.framework/QtGui
GM: /usr/local/Cellar/qt@5/5.15.2/lib/QtCore.framework/QtCore
GM: CMakeFiles/GM.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/kismet/Desktop/qt/stock/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Linking CXX executable GM"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GM.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GM.dir/build: GM

.PHONY : CMakeFiles/GM.dir/build

CMakeFiles/GM.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GM.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GM.dir/clean

CMakeFiles/GM.dir/depend: qrc_resource.cpp
	cd /Users/kismet/Desktop/qt/stock/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/kismet/Desktop/qt/stock /Users/kismet/Desktop/qt/stock /Users/kismet/Desktop/qt/stock/build /Users/kismet/Desktop/qt/stock/build /Users/kismet/Desktop/qt/stock/build/CMakeFiles/GM.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/GM.dir/depend
