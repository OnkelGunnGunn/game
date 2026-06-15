#include "dungeon_state.hpp"

DungeonState::DungeonState(GameData &data) : data(data)
{
}

void DungeonState::on_entry()
{
    clear_screen();

    std::cout << "Entering dungeon..." << std::endl;

    data.battle_type = DUNGEON;

    data.current_enemy = data.current_dungeon.get_current_enemy();
}


