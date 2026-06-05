#include <iostream>
#include <random>
#include <memory>
#include <vector>
#include "state.hpp"
#include "start_state.hpp"




void startState::on_entry()
{
    std::cout << "as you travel along in the forest a yellow mouse obstructs your path" << std::endl;
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
        new_state = CREATE_CHAR;
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