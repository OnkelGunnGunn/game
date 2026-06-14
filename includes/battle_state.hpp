#ifndef BATTLE_STATE_HPP
#define BATTLE_STATE_HPP
#include "state.hpp"
#include "monster.hpp"
#include "npc.hpp"
#include "game_data.hpp"

enum TurnOwner{
    PC = 1,
    OPPONENT = 2,
};

enum OnEntry{
    ENTER_BATTLE = 1,
    LEAVE_BATTLE_ENTRY
};

enum BattleActions{
    ATTACK = 1,
    // ITEM,
    // SWITCH,
    RUN
};


class BattleState : public State{

    private:
    GameData& data;
    Npc npc;
    Monster monster;
    TurnOwner turn;


    public:
    BattleState(GameData& data);
    void on_entry() override;
    int evaluate_user_input(int) override;
    TurnOwner who_starts();
    void print_actions();
    void print_health(std::vector<Monster>& monsters, int index);
    int battle();

    


};







#endif