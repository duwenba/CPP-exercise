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


# 遍历所有目标并添加复制 libstdc++-6.dll 的命令
get_property(targetList DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY BUILDSYSTEM_TARGETS)
foreach(target ${targetList})
    add_custom_command(TARGET ${target} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "C:/ProgramData/mingw64/mingw64/x86_64-w64-mingw32/lib/libstdc++-6.dll"
            $<TARGET_FILE_DIR:${target}>
    )
endforeach()

