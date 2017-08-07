cmake_minimum_required(VERSION 3.6)
project(geohash)
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES geohash.cpp)
add_executable(geohash ${SOURCE_FILES})