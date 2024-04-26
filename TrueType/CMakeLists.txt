cmake_minimum_required(VERSION 3.27)
project(Tables)

set(CMAKE_CXX_STANDARD 23)

include_directories("./")

file(GLOB_RECURSE SOURCES
        "Tables/*.cpp"
        "Readers/*.cpp"
)


add_executable(Tables ${SOURCES} main.cpp)
