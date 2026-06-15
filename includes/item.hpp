#ifndef ITEM_HPP
#define ITEM_HPP
#include <iostream>
#include "status.hpp"

class Monster;


enum class ItemType{
    POISON,
    STRENGTH_SAP,
    BOMB,
};

class Item{

    private:
    ItemType type;



    public:
    Item();
    Item(ItemType type);
    void use(Monster& enemy);




};







#endif