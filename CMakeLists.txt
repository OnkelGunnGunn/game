cmake_minimum_required(VERSION 3.16)

project(game LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

add_executable(game 
    src/main.cpp 
    src/monster.cpp 
    src/state.cpp
    src/start_state.cpp
    src/inventory_state.cpp
    )


target_include_directories(game PRIVATE includes)

