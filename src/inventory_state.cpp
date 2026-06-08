#include "inventory_state.hpp"
#include <iostream>

InventoryState::InventoryState()
{
    monsters.push_back(Monster("horse1", 4, 1));
    monsters.push_back(Monster("horse2", 4, 1));
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
    // Select swap so that the order in which the monsters are can be altered
    int a, b;

    switch (user_input)
    {
    case 1:
        std::cout << "choose option 1" << std::endl;
        std::cin >> a;
        std::cout << "choose option 2" << std::endl;
        std::cin >> b;
        swap_monsters(a - 1, b - 1);
        return INVENTORY;
        break;
    
    default:
        break;
    }
    return 0;
}

void InventoryState::swap_monsters(int i, int j)
{
    bool swapping = true;
    
    while(swapping){
        // std::cout << "Choose Monster to swap" << std::endl;
        // std::cin >> i;
        // std::cout << "Choose " << monsters[i].name << " new position" << std::endl;
        // std::cin >> j;
        std::swap(monsters[i], monsters[j]);
        swapping = false;
        if(i == 9 or j == 9){
            swapping = false;
        }
    }
    for (size_t i = 0; i < monsters.size(); ++i)
    {
        std::cout << i + 1 << ". " << monsters[i].name << std::endl;
    }
    
    // std::cout << "Choose Monster to swap" << std::endl;
    // std::cin >> i;
    // std::cout << "Choose " << monsters[i].name << " new position" << std::endl;
    // std::cin >> j;
    // std::swap(monsters[i], monsters[j]);
}
