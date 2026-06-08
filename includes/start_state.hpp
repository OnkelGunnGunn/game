#ifndef START_STATE_H
#define START_STATE_H

#include "state.hpp"
#include "game_data.hpp"

class startState : public State{
    private:
    GameData& data;


    public:
    startState(GameData& data);
    void on_entry() override;
    int evaluate_user_input(int) override;
};

#endif