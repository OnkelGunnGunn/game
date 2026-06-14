#include "ExploreState.hpp"




ExploreState::ExploreState(GameData &data) : data(data)
{
}


void ExploreState::on_entry()
{
    clear_screen();
    
    generate_random_encounters();

    
    std::cout << "You venture into the wild, on your path you encounter these Monsters, choose which one to fight: " << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "1. " << wild_monster[0].name << std::endl;
    std::cout << "2. " << wild_monster[1].name << std::endl;
    std::cout << "3. " << wild_monster[2].name << std::endl;
    std::cout << std::endl;
    std::cout << "4. Leave" << std::endl;

}

int ExploreState::evaluate_user_input(int user_input)
{
    // Switch state that activates battle state with the corresponding monster
    int new_state;

    
    switch (user_input)
    {
    case WILD_ENCOUNTER1:
        data.current_enemy = Npc(wild_monster[0].name);
        data.current_enemy.add_monster(wild_monster[0]);
        new_state = BATTLE;
        break;
        
    case WILD_ENCOUNTER2:
        data.current_enemy = Npc(wild_monster[1].name);
        data.current_enemy.add_monster(wild_monster[1]);
        new_state = BATTLE;
        break;

    case WILD_ENCOUNTER3:
        data.current_enemy = Npc(wild_monster[2].name);
        data.current_enemy.add_monster(wild_monster[2]);
        new_state = BATTLE;
        break;

    case EXIT_EXPLORE:
        new_state = LEAVE;
        break;

    default:
        new_state = EXPLORE;
        break;
    }

    

    return new_state;
}

Monster ExploreState::random_monster()
{
    return Monster("Horse", 4, 1);
}

Monster ExploreState::get_monster() const
{
    return encountered_monster;
}

void ExploreState::generate_random_encounters(){
    
    wild_monster.clear();
    wild_monster.resize(3);
    wild_monster[0] = random_monster();
    wild_monster[1] = random_monster();
    wild_monster[2] = random_monster();
}