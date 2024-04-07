cmake_minimum_required(VERSION 3.19)
project(pi)

#set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
#set(CMAKE_CXX_STANDARD 11)

include_directories(./)

file(GLOB_RECURSE SOURCES
        "token/*.cpp"
        "lexer/*.cpp"
        "configor/*.hpp"
        "ast/*.cpp"
        "parser/*.cpp"
        "object/*.cpp"
        "evaluator/*.cpp"
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/build/bin/DEBUG)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/build/bin/RELEASE)

add_executable(tokens  tokens.cpp ${SOURCES})
add_executable(ast ${SOURCES} ast.cpp)
add_executable(eval ${SOURCES} eval.cpp)
add_executable(eval_reply eval_reply.cpp ${SOURCES})
