#include <iostream>
#include <random>
#include "monster.hpp"


// Enums
enum BattleActions{
    ATTACK,
    SWITCH,
    EXIT_BATTLE,
};

enum TurnOwner{
    PC,
    OPPONENT
};

enum MenuState{
    START,
    EXPLORE,
    BATTLE,
    INVENTORY,
    MONSTER_DETAILS1,
    MONSTER_DETAILS2,
    MONSTER_DETAILS3,
    MONSTER_DETAILS4,
    RENAME,
    CREATE_CHAR,
    LEAVE,


};

enum SwitchMonster{
    SWITCHMONSTER1,
    SWITCHMONSTER2,
    SWITCHMONSTER3,
    SWITCHMONSTER4
};


// Back-end functions

int rng(int min, int max){
    static std::mt19937 generator(std::random_device{}());
    return std::uniform_int_distribution<>(min, max)(generator);
}

int wait_for_user_input(){
    int user_input;
    std::cin >> user_input;
    return user_input;
}

Monster spawn_random_monster(){
    switch(rng(0,7)){
        case 0:
            return Monster("Hest", 4, 1);
        case 1:
            return Monster("Weak Goblin", 4, 2);
        case 2:
            return Monster("Strong Goblin", 8, 3);
        case 3:
            return Monster("Stronger Goblin", 10, 4);
        case 4:
            return Monster("Den stærkeste Goblin", 15, 5);
        case 5:
            return Monster("Abe Kongen", 30, 5);
        case 6:
            return Monster("Enhjørning", 50, 8);
        case 7:
            return Monster("Drage", 100, 10);
        default:
            return Monster("Hest", 4, 1);
    }
}



// Print functions

void print_start_screen(){
    std::cout << "as you travel along in the forest a yellow mouse obstructs your path" << std::endl;
    std::cout << std::endl;
    std::cout << "which action do you want to take" << std::endl;
    std::cout << "1. Battle" << std::endl;
    std::cout << "2. explore" << std::endl;
    std::cout << "3. check monsters" << std::endl;
    std::cout << "4. Create new character" << std::endl;
    std::cout << "69. Leave Game" << std::endl;
 
}

void print_battle_screen(){
    std::cout << "get ready to rumble" << std::endl;
}

void print_explore_screen(){
    std::cout << "you continue further" << std::endl;
}

void print_battle_actions(){
    std::cout << std::endl;
    std::cout << "     Its your turn, choose your action" << std::endl;
    std::cout << "1. Attack     2. Switch Monster      3. Flee Battle" << std::endl;
}

void print_inventory_screen(Monster monster1, Monster monster2, Monster monster3, Monster monster4){
    std::cout << "Select monster:" << std::endl;
    std::cout << "1." << monster1.name << std::endl;
    std::cout << "2." << monster2.name << std::endl;
    std::cout << "3." << monster3.name << std::endl;
    std::cout << "4." << monster4.name << std::endl;
    std::cout << std::endl;
    std::cout << "press 0 to exit inventory" << std::endl;
}

void print_monster_details_screen(Monster monster){
    std::cout << "monster details:" << std::endl;
    std::cout << monster.name << std::endl;
    std::cout << "Damage: "<< monster.damage << std::endl;
    std::cout << "HP: " << monster.hp << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "1. Rename monster" << std::endl;
    std::cout << "2. Abandon monster" << std::endl;
    std::cout << "3. Exit monster details" << std::endl;

}

void print_switch_monster_menu(Monster monster1, Monster monster2, Monster monster3, Monster monster4){
    std::cout << "Choose Monster to use in battle" << std::endl;
    std::cout << std::endl;
    std::cout << "1. " << monster1.name << " 2. " << monster2.name << " 3. " << monster3.name << " 4. " << monster4.name << std::endl;
}

// Evaluate user_input
int evaluate_monster_details_input(int user_input, Monster &monster){
    int new_state;
    switch(user_input){

        case 1:
        new_state = RENAME;
        break;

        case 2:
        monster.abandon();
        new_state = INVENTORY;
        break;

        case 3:
        new_state = INVENTORY;
        break;


    }
    return new_state;
}

int evaluate_start_input(int user_input){
    int new_state;
    switch(user_input){
        
        case 1:
        new_state = BATTLE;
        break;

        case 2:
        new_state = EXPLORE;
        break;

        case 3:
        new_state = INVENTORY;
        break;

        case 4:
        new_state = CREATE_CHAR;
        break;

        case 69:
        new_state = LEAVE;
        break;

        default:
        new_state = START;
        break;
    }
    return new_state;
}

int evaluate_inventory_input(int user_input){
    int new_state;
    switch(user_input){

        case 0:
        new_state = START;
        break;
        
        case 1:
        new_state = MONSTER_DETAILS1;
        break;

        case 2:
        new_state = MONSTER_DETAILS2;
        break;
        
        case 3:
        new_state = MONSTER_DETAILS3;
        break;

        case 4:
        new_state = MONSTER_DETAILS4;
        break;

        default:
        new_state = INVENTORY;

    }
    return new_state;

}




void battle_mechanics(Monster& player, Monster& opponent){
    int dead = 0;
    int opp_hp = opponent.hp;
    int opp_dmg = opponent.damage;
    int pc_hp = player.hp;
    int pc_dmg = player.damage;
    bool battle = true;
    TurnOwner turn = static_cast<TurnOwner>(rng(0,1));
    int user_input;

    while(battle){
        switch(turn){

            case PC:
            print_battle_actions();
            user_input = wait_for_user_input();
                switch(user_input){
                    

                    case ATTACK:
                    std::cout << player.name << " dealt " << pc_dmg << " to " << opponent.name << std::endl;   //skal fjernes
                    opponent.hp -= player.damage;
                    if(opponent.hp <= dead){
                    std::cout << opponent.name << " has been defeated!" << std::endl;
                    battle = false;
                    }
                    else{
                    turn = OPPONENT;
                    }
                    break;


                    
                    


                }
                break;

            


            case OPPONENT:
            std::cout << opponent.name << " dealt " << opp_dmg << " to " << player.name << std::endl;   //skal fjernes
            player.hp -= opponent.damage;
            if(player.hp <= dead){
                std::cout << player.name << " has fainted!" << std::endl;
                battle = false;   
            }
            else{
               turn = PC;
            }
            break;

            default:
            std::cout << "Invalid turn value: " << turn << std::endl;
            battle = false;
            break;

        }
    }

}

// Main

int main(){
    Monster monster1("Player", 4, 1);
    Monster monster2("Opponent", 5, 1);
    Monster monster3;
    Monster monster4;
    std::string user_name = "Ash";
    int state = START;
    int user_input;
    bool running = true;

    while(running)
    {
        switch(state)
        {
            case START:
            print_start_screen();
            user_input = wait_for_user_input();
            state = evaluate_start_input(user_input);
            break;

            case BATTLE:
            //print_battle_screen();
            battle_mechanics(monster1, monster2); // Husk at få det ændret, så det er en modstander man spiller mod.
            print_start_screen();
            user_input = wait_for_user_input(); // bedre overgang til menu?
            break;

            case EXPLORE:
            print_explore_screen();
            break;

            case INVENTORY:
            print_inventory_screen(monster1, monster2, monster3, monster4);
            user_input = wait_for_user_input();
            state = evaluate_inventory_input(user_input);
            break;

            case MONSTER_DETAILS1:
            print_monster_details_screen(monster1);
            user_input = wait_for_user_input();
            state = evaluate_monster_details_input(user_input, monster1);
            break;

            case MONSTER_DETAILS2:
            print_monster_details_screen(monster2);
            user_input = wait_for_user_input();
            state = evaluate_monster_details_input(user_input, monster2);
            break;

            case MONSTER_DETAILS3:
            print_monster_details_screen(monster3);
            user_input = wait_for_user_input();
            state = evaluate_monster_details_input(user_input, monster3);
            break;

            case MONSTER_DETAILS4:
            print_monster_details_screen(monster4);
            user_input = wait_for_user_input();
            state = evaluate_monster_details_input(user_input, monster4);
            break;

            case CREATE_CHAR:
            std::cout << "Type name" << std::endl;
            std::cin >> user_name;
            std::cout << "Welcome " << user_name << " to my game: NotPokémon" << std::endl;
            monster1 = Monster("Hest", 4, 1);
            monster2 = Monster("Hest", 4, 1);
            monster3.abandon();
            monster4.abandon();
            state = START;
            break;

            case LEAVE:
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << "bai bai" << std::endl;
            running = false;
            break;

            default:
            std::cout << "sumting wong" << std::endl;
            running = false;
            break;

        }
        
    }

}

