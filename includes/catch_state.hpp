#ifndef CATCH_STATE_HPP
#define CATCH_STATE_HPP
#include "state.hpp"
#include "monster.hpp"
#include "player.hpp"
#include "game_data.hpp"

enum CatchActions{
    CATCH_MONSTER = 1,
    DONT_CATCH,
};

class CatchState : public State {
private:
    GameData& data;

public:
    CatchState(GameData& data);

    void on_entry() override;
    int evaluate_user_input(int) override;
};









#endif