#include "create_char_state.hpp"

CreateCharacterState::CreateCharacterState(GameData &data) : data(data)
{
}

void CreateCharacterState::on_entry()
{
    std::cout << "1. Create new Character     2. Leave" << std::endl;
}

int CreateCharacterState::evaluate_user_input(int user_input)
{
    switch (user_input)
    {
    case NEW_CHAR:
        clear_screen();
        std::cout << "Type your new player name" << std::endl;
        std::cin >> data.player_name;
        data.monsters.clear();
        data.monsters.push_back(Monster("horse1", 4, 1));
        data.monsters.push_back(Monster("horse2", 4, 1));
        data.monsters.push_back(Monster("none", 0, 0));
        data.monsters.push_back(Monster("none", 0, 0));
        break;
    
    case LEAVE_CHAR_CREATION:
        return START;


    default:
        std::cout << "sumting wong" << std::endl;
        break;
    }
    
    return START;
}
