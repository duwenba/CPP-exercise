cmake_minimum_required(VERSION 3.27)
project(TrueType)

set(CMAKE_CXX_STANDARD 23)

file(GLOB_RECURSE SOURCES
        "TrueType/*.cpp"
)


add_executable(TrueType ${SOURCES} main.cpp)
