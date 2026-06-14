#ifndef INVENTORY_STATE_HPP
#define INVENTORY_STATE_HPP

#include <vector>
#include "state.hpp"
#include "monster.hpp"
#include "game_data.hpp"

enum InventoryOptions{
    SWAP,
    ITEM,
    EXIT_INV,
};

class InventoryState : public State{

    private:
    GameData& data;


    public:
    InventoryState(GameData& data);
    void on_entry() override;
    int evaluate_user_input(int) override;
    void swap_monsters();
    

};







#endif