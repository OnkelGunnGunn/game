#include <iostream>
#include <random>
#include <memory>
#include <vector>
#include "state.hpp"
#include "start_state.hpp"
#include "create_char_state.hpp"

startState::startState(GameData &data) : data(data)
{
    data.player.add_monster(Monster("Player's HEST 1", 4, 1));
    data.player.add_monster(Monster("player's HEST 2", 4, 1));
    data.player.add_monster(Monster("player's HEST 3", 4, 1));
    data.player.add_monster(Monster("player's HEST 4", 4, 1));
    
}

void startState::on_entry()
{
    clear_screen();
    std::cout << "Hello " << data.player.get_name() << ", choose an option." << std::endl;
    std::cout << std::endl;
    std::cout << "which action do you want to take" << std::endl;
    std::cout << "1. Battle" << std::endl;
    std::cout << "2. explore" << std::endl;
    std::cout << "3. check monsters" << std::endl;
    std::cout << "4. Create new character" << std::endl;
    std::cout << "69. Leave Game" << std::endl;
}

int startState::evaluate_user_input(int user_input)
{
    int new_state;
    switch(user_input){
        
        case 1:
        new_state = BATTLE;
        break;

        case 2:
        new_state = EXPLORE;
        break;

        case 3:
        new_state = INVENTORY;
        break;

        case 4:
        new_state = CREATE_CHARACTER;
        break;

        case 69:
        new_state = LEAVE;
        break;

        default:
        new_state = START;
        break;
    }
    return new_state;
    
}