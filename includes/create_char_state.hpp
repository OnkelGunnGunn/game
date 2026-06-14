#ifndef CREATE_CHAR_HPP
#define CREATE_CHAR_HPP
#include "state.hpp"
#include "game_data.hpp"
#include "monster.hpp"


enum CharCreation{
    NEW_CHAR = 1,
    LEAVE_CHAR_CREATION = 2
};

class CreateCharacterState : public State{
    private:
    GameData& data;

    public:
    CreateCharacterState(GameData& data);
    void on_entry() override;
    int evaluate_user_input(int) override;


};












#endif