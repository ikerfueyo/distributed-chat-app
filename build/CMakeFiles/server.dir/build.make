# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.30.3/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.30.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ikerfueyo/distributed-chat-app

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ikerfueyo/distributed-chat-app/build

# Include any dependencies generated for this target.
include CMakeFiles/server.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/server.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/server.dir/flags.make

CMakeFiles/server.dir/server/src/Server.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/server/src/Server.cpp.o: /Users/ikerfueyo/distributed-chat-app/server/src/Server.cpp
CMakeFiles/server.dir/server/src/Server.cpp.o: CMakeFiles/server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/ikerfueyo/distributed-chat-app/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/server.dir/server/src/Server.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/server.dir/server/src/Server.cpp.o -MF CMakeFiles/server.dir/server/src/Server.cpp.o.d -o CMakeFiles/server.dir/server/src/Server.cpp.o -c /Users/ikerfueyo/distributed-chat-app/server/src/Server.cpp

CMakeFiles/server.dir/server/src/Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/server.dir/server/src/Server.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ikerfueyo/distributed-chat-app/server/src/Server.cpp > CMakeFiles/server.dir/server/src/Server.cpp.i

CMakeFiles/server.dir/server/src/Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/server.dir/server/src/Server.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ikerfueyo/distributed-chat-app/server/src/Server.cpp -o CMakeFiles/server.dir/server/src/Server.cpp.s

CMakeFiles/server.dir/server/src/ClientHandler.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/server/src/ClientHandler.cpp.o: /Users/ikerfueyo/distributed-chat-app/server/src/ClientHandler.cpp
CMakeFiles/server.dir/server/src/ClientHandler.cpp.o: CMakeFiles/server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/ikerfueyo/distributed-chat-app/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/server.dir/server/src/ClientHandler.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/server.dir/server/src/ClientHandler.cpp.o -MF CMakeFiles/server.dir/server/src/ClientHandler.cpp.o.d -o CMakeFiles/server.dir/server/src/ClientHandler.cpp.o -c /Users/ikerfueyo/distributed-chat-app/server/src/ClientHandler.cpp

CMakeFiles/server.dir/server/src/ClientHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/server.dir/server/src/ClientHandler.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ikerfueyo/distributed-chat-app/server/src/ClientHandler.cpp > CMakeFiles/server.dir/server/src/ClientHandler.cpp.i

CMakeFiles/server.dir/server/src/ClientHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/server.dir/server/src/ClientHandler.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ikerfueyo/distributed-chat-app/server/src/ClientHandler.cpp -o CMakeFiles/server.dir/server/src/ClientHandler.cpp.s

CMakeFiles/server.dir/server/src/Encryption.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/server/src/Encryption.cpp.o: /Users/ikerfueyo/distributed-chat-app/server/src/Encryption.cpp
CMakeFiles/server.dir/server/src/Encryption.cpp.o: CMakeFiles/server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/ikerfueyo/distributed-chat-app/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/server.dir/server/src/Encryption.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/server.dir/server/src/Encryption.cpp.o -MF CMakeFiles/server.dir/server/src/Encryption.cpp.o.d -o CMakeFiles/server.dir/server/src/Encryption.cpp.o -c /Users/ikerfueyo/distributed-chat-app/server/src/Encryption.cpp

CMakeFiles/server.dir/server/src/Encryption.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/server.dir/server/src/Encryption.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ikerfueyo/distributed-chat-app/server/src/Encryption.cpp > CMakeFiles/server.dir/server/src/Encryption.cpp.i

CMakeFiles/server.dir/server/src/Encryption.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/server.dir/server/src/Encryption.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ikerfueyo/distributed-chat-app/server/src/Encryption.cpp -o CMakeFiles/server.dir/server/src/Encryption.cpp.s

CMakeFiles/server.dir/server/src/Logger.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/server/src/Logger.cpp.o: /Users/ikerfueyo/distributed-chat-app/server/src/Logger.cpp
CMakeFiles/server.dir/server/src/Logger.cpp.o: CMakeFiles/server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/ikerfueyo/distributed-chat-app/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/server.dir/server/src/Logger.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/server.dir/server/src/Logger.cpp.o -MF CMakeFiles/server.dir/server/src/Logger.cpp.o.d -o CMakeFiles/server.dir/server/src/Logger.cpp.o -c /Users/ikerfueyo/distributed-chat-app/server/src/Logger.cpp

CMakeFiles/server.dir/server/src/Logger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/server.dir/server/src/Logger.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ikerfueyo/distributed-chat-app/server/src/Logger.cpp > CMakeFiles/server.dir/server/src/Logger.cpp.i

CMakeFiles/server.dir/server/src/Logger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/server.dir/server/src/Logger.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ikerfueyo/distributed-chat-app/server/src/Logger.cpp -o CMakeFiles/server.dir/server/src/Logger.cpp.s

CMakeFiles/server.dir/server/src/FaultTolerance.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/server/src/FaultTolerance.cpp.o: /Users/ikerfueyo/distributed-chat-app/server/src/FaultTolerance.cpp
CMakeFiles/server.dir/server/src/FaultTolerance.cpp.o: CMakeFiles/server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/ikerfueyo/distributed-chat-app/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/server.dir/server/src/FaultTolerance.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/server.dir/server/src/FaultTolerance.cpp.o -MF CMakeFiles/server.dir/server/src/FaultTolerance.cpp.o.d -o CMakeFiles/server.dir/server/src/FaultTolerance.cpp.o -c /Users/ikerfueyo/distributed-chat-app/server/src/FaultTolerance.cpp

CMakeFiles/server.dir/server/src/FaultTolerance.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/server.dir/server/src/FaultTolerance.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ikerfueyo/distributed-chat-app/server/src/FaultTolerance.cpp > CMakeFiles/server.dir/server/src/FaultTolerance.cpp.i

CMakeFiles/server.dir/server/src/FaultTolerance.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/server.dir/server/src/FaultTolerance.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ikerfueyo/distributed-chat-app/server/src/FaultTolerance.cpp -o CMakeFiles/server.dir/server/src/FaultTolerance.cpp.s

CMakeFiles/server.dir/server/src/LoadBalancer.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/server/src/LoadBalancer.cpp.o: /Users/ikerfueyo/distributed-chat-app/server/src/LoadBalancer.cpp
CMakeFiles/server.dir/server/src/LoadBalancer.cpp.o: CMakeFiles/server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/ikerfueyo/distributed-chat-app/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/server.dir/server/src/LoadBalancer.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/server.dir/server/src/LoadBalancer.cpp.o -MF CMakeFiles/server.dir/server/src/LoadBalancer.cpp.o.d -o CMakeFiles/server.dir/server/src/LoadBalancer.cpp.o -c /Users/ikerfueyo/distributed-chat-app/server/src/LoadBalancer.cpp

CMakeFiles/server.dir/server/src/LoadBalancer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/server.dir/server/src/LoadBalancer.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ikerfueyo/distributed-chat-app/server/src/LoadBalancer.cpp > CMakeFiles/server.dir/server/src/LoadBalancer.cpp.i

CMakeFiles/server.dir/server/src/LoadBalancer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/server.dir/server/src/LoadBalancer.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ikerfueyo/distributed-chat-app/server/src/LoadBalancer.cpp -o CMakeFiles/server.dir/server/src/LoadBalancer.cpp.s

# Object files for target server
server_OBJECTS = \
"CMakeFiles/server.dir/server/src/Server.cpp.o" \
"CMakeFiles/server.dir/server/src/ClientHandler.cpp.o" \
"CMakeFiles/server.dir/server/src/Encryption.cpp.o" \
"CMakeFiles/server.dir/server/src/Logger.cpp.o" \
"CMakeFiles/server.dir/server/src/FaultTolerance.cpp.o" \
"CMakeFiles/server.dir/server/src/LoadBalancer.cpp.o"

# External object files for target server
server_EXTERNAL_OBJECTS =

server: CMakeFiles/server.dir/server/src/Server.cpp.o
server: CMakeFiles/server.dir/server/src/ClientHandler.cpp.o
server: CMakeFiles/server.dir/server/src/Encryption.cpp.o
server: CMakeFiles/server.dir/server/src/Logger.cpp.o
server: CMakeFiles/server.dir/server/src/FaultTolerance.cpp.o
server: CMakeFiles/server.dir/server/src/LoadBalancer.cpp.o
server: CMakeFiles/server.dir/build.make
server: libshared_lib.a
server: /usr/local/Cellar/openssl@3/3.3.1/lib/libssl.dylib
server: /usr/local/Cellar/openssl@3/3.3.1/lib/libcrypto.dylib
server: CMakeFiles/server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/ikerfueyo/distributed-chat-app/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/server.dir/build: server
.PHONY : CMakeFiles/server.dir/build

CMakeFiles/server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/server.dir/clean

CMakeFiles/server.dir/depend:
	cd /Users/ikerfueyo/distributed-chat-app/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ikerfueyo/distributed-chat-app /Users/ikerfueyo/distributed-chat-app /Users/ikerfueyo/distributed-chat-app/build /Users/ikerfueyo/distributed-chat-app/build /Users/ikerfueyo/distributed-chat-app/build/CMakeFiles/server.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/server.dir/depend

