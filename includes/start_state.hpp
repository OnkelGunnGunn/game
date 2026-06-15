#ifndef START_STATE_HPP
#define START_STATE_HPP

#include "state.hpp"
#include "game_data.hpp"

class startState : public State{
    private:
    GameData& data;
    Database_interface db_interface;

    public:
    startState(GameData& data);
    void on_entry() override;
    int evaluate_user_input(int) override;
};

#endif