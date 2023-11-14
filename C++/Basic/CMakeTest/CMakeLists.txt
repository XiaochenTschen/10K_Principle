cmake_minimum_required(VERSION 3.10)

# Set the project name
project(MyProject)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/src)

# Create a variable to hold source files
set(SOURCES
    main.cpp
    src/func.cpp
)

# Create the executable using the source files
add_executable(my_program ${SOURCES})

