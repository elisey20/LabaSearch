cmake_minimum_required(VERSION 3.17)
project(LabSearch)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES source/methods.cpp)

add_executable(LabSearch main.cpp ${SOURCE_FILES})
add_executable(test forTests.cpp)

target_include_directories(LabSearch PRIVATE source)