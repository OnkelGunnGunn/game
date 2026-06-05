#include <iostream>
#include <random>
#include <memory>
#include <vector>
#include "state.hpp"

enum MenuState{
    START,
    EXPLORE,
    BATTLE,
    INVENTORY,
    MONSTER_DETAILS1,
    MONSTER_DETAILS2,
    MONSTER_DETAILS3,
    MONSTER_DETAILS4,
    RENAME,
    CREATE_CHAR,
    LEAVE,


};


class State{
    private:


    public:
    virtual ~State() = default;
    virtual void on_entry() = 0;
    virtual int evaluate_user_input(int) = 0;



};

class startState : public State{
    private:


    public:
    void on_entry() override;
    int evaluate_user_input(int) override;
};


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


int main(){
    std::vector<std::unique_ptr<State>> states;
    states.push_back(std::make_unique<startState>());

    states[0]->on_entry();

    int user_input;
    std::cin >> user_input;
    int next_state = states[0]->evaluate_user_input(user_input);
    std::cout << "Next state is " << next_state << std::endl;
}