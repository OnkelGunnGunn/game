#include "inventory_state.hpp"
#include <iostream>

InventoryState::InventoryState()
{
    monsters.push_back(Monster("horse", 4, 1));
    monsters.push_back(Monster("horse", 4, 1));
    monsters.push_back(Monster("none", 0, 0));
    monsters.push_back(Monster("none", 0, 0));
}

void InventoryState::on_entry()
{
    std::cout << "Select monster:" << std::endl;
    std::cout << "1." << monsters[0].name << std::endl;
    std::cout << "2." << monsters[1].name << std::endl;
    std::cout << "3." << monsters[2].name << std::endl;
    std::cout << "4." << monsters[3].name << std::endl;
    std::cout << std::endl;
    std::cout << "press 5 to exit inventory" << std::endl;

}

int InventoryState::evaluate_user_input(int user_input)
{
    // std::cin >> user_input;

    // Monster& selected = monsters[user_input - 1];


     return 0;
}

void InventoryState::swap_monsters(int i, int j)
{
    std::swap(monsters[i], monsters[j]);
}
