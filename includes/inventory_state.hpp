#ifndef INVENTORY_STATE_H
#define INVENTORY_STATE_H

#include <vector>
#include "state.hpp"
#include "monster.hpp"

enum MonsterDETAILS{
    MONSTER_DETAILS1,
    MONSTER_DETAILS2,
    MONSTER_DETAILS3,
    MONSTER_DETAILS4,
};

class InventoryState : public State{

    private:
    std::vector<Monster> monsters;


    public:
    InventoryState();
    void on_entry() override;
    int evaluate_user_input(int) override;
    void swap_monsters(int, int);
    

};







#endif