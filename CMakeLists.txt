# Specify the minimum version of CMake
cmake_minimum_required(VERSION 3.10)

# Define the project name and version
project(DistributedChatApp VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find the OpenSSL package (required for encryption)
find_package(OpenSSL REQUIRED)

# Google Test setup for unit testing
find_package(GTest REQUIRED)
enable_testing()

# Add include directories for headers
include_directories(
    client/include
    server/include
    shared
    /usr/local/include
)

# Add the shared library (for common utilities like Message and Encryption)
add_library(shared_lib
    shared/Message.cpp
    shared/Encryption.cpp
    shared/Constants.h
)

# Link OpenSSL to the shared library
target_link_libraries(shared_lib OpenSSL::SSL OpenSSL::Crypto)

#####################################
# Building the client application
#####################################
add_executable(client
    client/src/Client.cpp
    client/src/UI.cpp
    client/src/Encryption.cpp
)

# Link the shared library and OpenSSL to the client
target_link_libraries(client shared_lib OpenSSL::SSL OpenSSL::Crypto)

#####################################
# Building the server application
#####################################
add_executable(server
    server/src/Server.cpp
    server/src/ClientHandler.cpp
    server/src/Encryption.cpp
    server/src/Logger.cpp
    server/src/FaultTolerance.cpp
    server/src/LoadBalancer.cpp
)

# Link the shared library and OpenSSL to the server
target_link_libraries(server shared_lib OpenSSL::SSL OpenSSL::Crypto)

#####################################
# Unit tests for client, server, and shared libraries
#####################################
# Create a test executable for shared tests
add_executable(shared_test
    shared/test/shared_test.cpp
)

# Link Google Test and shared_lib for shared tests
target_link_libraries(shared_test
    GTest::GTest
    GTest::Main
    shared_lib
)

# Create a test executable for client tests
add_executable(client_test
    client/test/client_test.cpp
)

# Link Google Test, client, and shared libraries for client tests
target_link_libraries(client_test
    GTest::GTest
    GTest::Main
    shared_lib
)

# Create a test executable for server tests
add_executable(server_test
    server/test/server_test.cpp
)

# Link Google Test, server, and shared libraries for server tests
target_link_libraries(server_test
    GTest::GTest
    GTest::Main
    shared_lib
)

#####################################
# Enable testing
#####################################
add_test(NAME SharedTest COMMAND shared_test)
add_test(NAME ClientTest COMMAND client_test)
add_test(NAME ServerTest COMMAND server_test)

#####################################
# Installation setup (optional)
#####################################
install(TARGETS client DESTINATION bin)
install(TARGETS server DESTINATION bin)
install(TARGETS shared_lib DESTINATION lib)
install(FILES
    client/include/Client.h
    server/include/Server.h
    shared/Message.h
    shared/Encryption.h
    shared/Constants.h
    DESTINATION include
)
