#ifndef DUNGEON_STATE_HPP
#define DUNGEON_STATE_HPP
#include "state.hpp"
#include "game_data.hpp"


class DungeonState : public State {
private:
    GameData& data;

public:
    DungeonState(GameData& data);

    void on_entry() override;
    int evaluate_user_input(int user_input) override;
};





#endif