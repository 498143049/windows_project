cmake_minimum_required(VERSION 3.6)
project(sudo)
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES sudo.cpp)
add_executable(sudo ${SOURCE_FILES})