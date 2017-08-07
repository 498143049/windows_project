cmake_minimum_required(VERSION 3.6)
project(mutex)
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES mutex.cpp)
add_executable(mutex ${SOURCE_FILES})