#include "inventory_state.hpp"
#include <iostream>
#include "game_data.hpp"
#include "player.hpp"

InventoryState::InventoryState(GameData &data) : data(data)
{
}


void InventoryState::on_entry()
{
    clear_screen();
    std::cout << "Monsters in your Party" << std::endl;
    for (size_t i = 0; i < data.player.get_all_monsters().size(); ++i)
    {
        std::cout << i + 1 << ". " << data.player.get_all_monsters()[i].name << "       (HP: " << data.player.get_all_monsters()[i].hp << "  DMG: " << data.player.get_all_monsters()[i].damage << ")" << std::endl;
    }

    std::cout << "Choose option:" << std::endl;  
    std::cout << "0. Swap order of monsters            2. Leave inventory" << std::endl;
}


int InventoryState::evaluate_user_input(int user_input)
{
    // Select swap so that the order in which the monsters are can be altered



    switch (user_input){
        case SWAP:
            swap_monsters();
            return INVENTORY;
            break;
        
        // case 2 item

        case EXIT_INV:
        return START;

        default:
            break;
    }
    return 0;
}

void InventoryState::swap_monsters()
{
    bool swapping = true;
    int i;
    int j;

    while(swapping){
        if(i == 9 or j == 9){
            std::cout << "Swapping cancelled" << std::endl;
            swapping = false;
        }
        else{
        std::cout << "monster 1" << std::endl;
        std::cin >> i;
        std::cout << "monster 2" << std::endl;
        std::cin >> j;

        std::swap(data.player.get_all_monsters()[i-1], data.player.get_all_monsters()[j-1]);
        swapping = false;
        }
    


    std::cout << "New Monster order:" << std::endl;
    for (size_t i = 0; i < data.player.get_all_monsters().size(); ++i)
    {
        std::cout << i << ". " << data.player.get_all_monsters()[i].name << std::endl;
    }
    
}
}
