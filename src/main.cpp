#include <iostream>

enum State{
    START = 0,
    EXPLORE = 1,
    BATTLE = 2,
    INVENTORY = 3,
    MONSTER_DETAILS1 = 4,
    MONSTER_DETAILS2 = 5,
    MONSTER_DETAILS3 = 6,
    MONSTER_DETAILS4 = 7
    
};

void print_start_screen(){
    std::cout << "as you travel along in the forest a yellow mouse obstructs your path" << std::endl;
    std::cout << std::endl;
    std::cout << "which action do you want to take" << std::endl;
    std::cout << "1. Battle" << std::endl;
    std::cout << "2. explore" << std::endl;
    std::cout << "3. check monsters" << std::endl;
 
}

int wait_for_user_input(){
    int user_input;
    std::cin >> user_input;
    return user_input;
}

void print_battle_screen(){
    std::cout << "get ready to rumble" << std::endl;
}

void print_explore_screen(){
    std::cout << "you continue further" << std::endl;
}

void print_inventory_screen(){
    std::cout << "Select monster:" << std::endl;
    std::cout << "1. pikachu" << std::endl;
    std::cout << "2. squirtle" << std::endl;

}

void print_monster_details_screen(){
    std::cout << "monster details:" << std::endl;
    std::cout << "Pikachu  LVL 47"  << std::endl;
    std::cout << "Damage: 12" << std::endl;
    std::cout << "HP: 47" << std::endl;
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

        default:
        new_state = START;
        break;
    }
    return new_state;
}

int evaluate_inventory_input(int user_input){
    int new_state;
    switch(user_input){

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

    }
    return new_state;

}



int main(){
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
            print_battle_screen();
            break;

            case EXPLORE:
            print_explore_screen();
            break;

            case INVENTORY:
            print_inventory_screen();
            user_input = wait_for_user_input();
            state = evaluate_inventory_input(user_input);
            break;

            case MONSTER_DETAILS1:
            print_monster_details_screen();
            break;

            case MONSTER_DETAILS2:
            print_monster_details_screen();
            break;

            case MONSTER_DETAILS3:
            print_monster_details_screen();
            break;

            case MONSTER_DETAILS4:
            print_monster_details_screen();
            break;

            default:
            std::cout << "sumting wong" << std::endl;

        }
        
    }

}

