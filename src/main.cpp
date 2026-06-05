#include <iostream>
#include <random>
#include <memory>
#include <vector>
#include "state.hpp"
#include "start_state.hpp"


int main(){
    std::vector<std::unique_ptr<State>> states;
    states.push_back(std::make_unique<startState>());

    states[0]->on_entry();

    int user_input;
    std::cin >> user_input;
    int next_state = states[0]->evaluate_user_input(user_input);
    std::cout << "Next state is " << next_state << std::endl;
}