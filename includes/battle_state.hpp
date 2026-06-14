#ifndef BATTLE_STATE_HPP
#define BATTLE_STATE_HPP
#include "state.hpp"
#include "monster.hpp"
#include "npc.hpp"
#include "game_data.hpp"

class BattleState : public State{

    private:
    GameData& data;
    Npc npc;
    Monster monster;


    public:
    BattleState(GameData& data);
    void on_entry() override;
    int evaluate_user_input(int) override;


};







#endif