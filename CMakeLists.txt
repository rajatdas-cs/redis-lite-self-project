cmake_minimum_required(VERSION 3.10)
project(redis-lite)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(include)

# Source files
file(GLOB SOURCES
    src/*.cpp
    main.cpp
)

# Define the executable
add_executable(redis-lite ${SOURCES})