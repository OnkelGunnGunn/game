#include <iostream>
#include <random>
#include <memory>
#include <vector>
#include "state.hpp"
#include "start_state.hpp"
#include "create_char_state.hpp"

startState::startState(GameData &data) : data(data)
{
    
    data.player.add_monster(Monster("Hest", 4, 1));
    data.player.add_monster(Monster("Hest", 4, 1));
    data.player.add_monster(Monster());
    data.player.add_monster(Monster());
    
}

void startState::on_entry()
{
    // clear_screen();
    std::cout << "Hello " << data.player.get_name() << ", choose an option." << std::endl;
    std::cout << std::endl;
    std::cout << "which action do you want to take" << std::endl;
    std::cout << "1. explore" << std::endl;
    std::cout << "2. check monsters" << std::endl;
    std::cout << "3. Create new character" << std::endl;
    std::cout << "4. Save game" << std::endl;
    std::cout << LEAVE << ". Leave Game" << std::endl;
}

int startState::evaluate_user_input(int user_input)
{
    int new_state;
    switch(user_input){
        
        case EXPLORE:
        new_state = EXPLORE;
        break;

        case INVENTORY:
        new_state = INVENTORY;
        break;

        case CREATE_CHARACTER:
        new_state = CREATE_CHARACTER;
        break;

        case LEAVE:
        new_state = LEAVE;
        break;

        case SAVE:
        db_interface.save_game_data(data.player);
        new_state = START;
        break;


        default:
        new_state = START;
        break;
    }
    return new_state;
    
}