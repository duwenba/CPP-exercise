cmake_minimum_required(VERSION 3.28)
project(vc_freetype)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/target/DEBUG)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/target/RELEASE)


find_package(Freetype CONFIG REQUIRED)
find_package(PNG REQUIRED)

add_executable(vc_freetype main.cpp)
target_link_libraries(vc_freetype Freetype::Freetype)
target_link_libraries(vc_freetype PNG::PNG)