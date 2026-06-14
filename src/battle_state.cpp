#include "battle_state.hpp"
#include "player.hpp"
#include "npc.hpp"
#include "monster.hpp"
#include <iostream>


BattleState::BattleState(GameData &data) : data(data)
{
}

void BattleState::on_entry()
{
    clear_screen();
    std::cout << "LETS GET READY TO RUMBLE!!!" << std::endl;
    std::cout << "1. Battle against " << data.current_enemy.get_name() << "     2. Leave" << std::endl;
    
}

int BattleState::evaluate_user_input(int user_input)
{
    clear_screen();
    int new_state;
    switch (user_input)
    {
    
    case ENTER_BATTLE: 
        return battle();
    break;
    

    case LEAVE_BATTLE_ENTRY:
        new_state = LEAVE;
    break;
    

    default:
        new_state = BATTLE;
    break;
    }
    

    return new_state;
}

TurnOwner BattleState::who_starts()
{
    TurnOwner decider = static_cast<TurnOwner>(rng(1,2));

    if(decider == 1){
        std::cout << "Player starts!" << std::endl;
    }
    else{
        std::cout << "Enemy starts!" << std::endl;
    }
    spacing();

    return TurnOwner(decider);
}

void BattleState::print_actions()
{
    std::cout << "Choose what action " << data.player.get_monster(0).name << " should take!" << std::endl;
    std::cout << "1. Attack " << data.current_enemy.get_name() << std::endl;
    std::cout << "2. Switch" << std::endl;
    std::cout << "3. Leave battle" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
}

void BattleState::print_health(std::vector<Monster>& monsters, int index)
{

    if (index >= 0 && index < monsters.size())
        {
            std::cout << monsters[index].name
                    << " HP: "
                    << monsters[index].hp
                    << std::endl;
        }

}

int BattleState::battle()
{
    int dead = 0;
    bool fighting = true;
    int user_input;
    int new_state = BATTLE;
    int i_player = 0;
    int i_enemy = 0;
    turn = who_starts();

    auto player_monsters = data.player.get_all_monsters();
    auto enemy_monsters  = data.current_enemy.get_all_monsters();

    while (fighting)
    {
        switch (turn)
        {
        case PC:
        {
            std::cout << "Player Monster health:" << std::endl;
            print_health(player_monsters,i_player);
            spacing();
            
            print_actions();
            

            std::cin >> user_input;

            switch (user_input)
            {
            case ATTACK:     // Switches to opponent to fast?
            {   clear_screen();
                std::cout << player_monsters[i_player].name << " dealt "
                          << player_monsters[i_player].damage << " to "
                          << enemy_monsters[i_enemy].name << std::endl;
                spacing();

                enemy_monsters[i_enemy].hp -= player_monsters[i_player].damage; // Make into a function?


                
                if (enemy_monsters[i_enemy].hp <= dead)   // Make into a function?
                {
                    std::cout << enemy_monsters[i_enemy].name
                            << " has been defeated!" << std::endl;

                    i_enemy++;

                    if (i_enemy >= enemy_monsters.size())
                    {
                        std::cout << "All enemy monsters defeated!\n";
                        new_state = START;
                        fighting = false;
                        break;   
                    }
                }
                else
                {
                    turn = OPPONENT;
                }
                break;
            }

            case RUN:
                new_state = LEAVE;
                fighting = false;
                break;


            default:
                // turn = PC;
                break;
            }
            break;
        }

        case OPPONENT:
        {   clear_screen();
            std::cout << "enemy attacking" << std::endl;
            std::cout << enemy_monsters[i_enemy].name << " dealt "
                      << enemy_monsters[i_enemy].damage << " to "
                      << player_monsters[i_player].name << std::endl;
            spacing();

            player_monsters[i_player].hp -= enemy_monsters[i_enemy].damage;

            std::cout << "Enemy Monster health:" << std::endl;
            print_health(enemy_monsters, i_enemy);
            spacing();

           

            if (player_monsters[i_player].hp <= dead)
            {
                std::cout << player_monsters[i_player].name
                          << " has fainted!" << std::endl;
                i_player++;

                if (i_player >= player_monsters.size())
                {
                    std::cout << "All your monsters have fainted!\n";
                    new_state = START;
                    fighting = false;
                    break;
                }
                
            }
            else
            {
                turn = PC;
            }
            break;
        }

        default:
            break;
        }
    }
    return new_state;

    
}



// if won = catch state, if not = startState