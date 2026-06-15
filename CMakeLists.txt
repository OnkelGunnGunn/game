cmake_minimum_required(VERSION 3.16)

project(game LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

add_executable(game 
    src/main.cpp 
    src/monster.cpp 
    src/state.cpp
    src/start_state.cpp
    src/inventory_state.cpp
    src/create_char_state.cpp
    src/battle_state.cpp
    src/npc.cpp
    src/player.cpp
    src/ExploreState.cpp
    src/catch_state.cpp
    src/item.cpp
    src/status.cpp
    src/dungeon.cpp
    )


target_include_directories(game PRIVATE includes)

find_package(SQLite3 REQUIRED)

target_link_libraries(game PRIVATE sqlite3)

