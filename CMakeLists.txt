cmake_minimum_required(VERSION 3.10)
project(cpp_search LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Include directories for both modules
include_directories(
    ${CMAKE_SOURCE_DIR}/include
)

# Gather all source files from utils, maze, and main.c
file(GLOB SOURCES
    ${CMAKE_SOURCE_DIR}/main.cpp
    ${CMAKE_SOURCE_DIR}/src/*.cpp
)

# Create the executable
add_executable(app ${SOURCES})
