cmake_minimum_required(VERSION 3.27)
project(BTree)

set(CMAKE_CXX_STANDARD 23)

file(GLOB_RECURSE SOURCES *.cpp *.hpp)

add_executable(main main.cpp)
