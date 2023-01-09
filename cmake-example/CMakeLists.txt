# CMake Minimum Version
cmake_minimum_required(VERSION 3.11)

# Project Information
project(
    ModooCode
    VERSION 0.1
    DESCRIPTION "Example Project"
    LANGUAGES CXX
)

# Add directory
add_subdirectory(lib)

add_executable(program main.cpp)

# Link shape to program
target_link_libraries(program shape)

# target_compile_options(program PUBLIC -Wall -Werror)

# target_include_directories(program PUBLIC ${CMAKE_SOURCE_DIR}/include)