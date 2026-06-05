#include <iostream>
#include <random>
#include <memory>
#include <vector>
#include "state.hpp"
#include "start_state.hpp"
#include "inventory_state.hpp"


int main(){

    std::vector<std::unique_ptr<State>> states(LEAVE + 1);

    states[START]        = std::make_unique<startState>();
    states[INVENTORY]    = std::make_unique<InventoryState>();
    states[BATTLE]       = std::make_unique<startState>();   // temp
    states[EXPLORE]      = std::make_unique<startState>();   // temp
    states[CREATE_CHAR]  = std::make_unique<startState>();   // temp

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