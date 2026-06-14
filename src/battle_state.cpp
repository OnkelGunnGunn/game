#include "battle_state.hpp"
#include "player.hpp"
#include "npc.hpp"
#include <iostream>


BattleState::BattleState(GameData &data) : data(data)
{
}

void BattleState::on_entry()
{
    std::cout << "Lets get ready to rumble!" << std::endl;
    std::cout << "1. Battle " << npc.get_name() << "   2. Leave battle" << std::endl;
}

int BattleState::evaluate_user_input(int)
{

    return 0;
}
