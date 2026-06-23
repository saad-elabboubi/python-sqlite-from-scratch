cmake_minimum_required(VERSION 3.13)

project(sqlite-file-reader-cpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCE_FILES src/*.cpp src/*.hpp)

add_executable(sqlite ${SOURCE_FILES})
