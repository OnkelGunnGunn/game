#include <iostream>
#include <random>
#include <memory>
#include <vector>
#include "state.hpp"
#include "start_state.hpp"
#include "inventory_state.hpp"
#include "create_char_state.hpp"
#include "ExploreState.hpp"
#include "battle_state.hpp"
#include "catch_state.hpp"


int main(){

    GameData data;

    std::vector<std::unique_ptr<State>> states(LEAVE + 1);

    states[START]             = std::make_unique<startState>(data);
    states[INVENTORY]         = std::make_unique<InventoryState>(data);
    states[BATTLE]            = std::make_unique<BattleState>(data); 
    states[EXPLORE]           = std::make_unique<ExploreState>(data); 
    states[CREATE_CHARACTER]  = std::make_unique<CreateCharacterState>(data);
    states[CATCH]             = std::make_unique<CatchState>(data);

    int current_state = START;

    


    while (current_state != LEAVE)
    {
        if (!states[current_state]) {
            std::cout << "ERROR: State not initialized: " << current_state << std::endl;
            break;
        }

        states[current_state]->on_entry();
        
        int input;
        std::cin >> input;

        current_state = states[current_state]->evaluate_user_input(input);
    }

    return 0;
}