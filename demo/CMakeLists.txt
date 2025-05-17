cmake_minimum_required(VERSION 3.10)

project(demo)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(demo main.cpp ${CMAKE_CURRENT_SOURCE_DIR}/../stacktrace.cpp)
