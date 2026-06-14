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
    std::string new_name;
    switch (user_input)
    {
    case NEW_CHAR:
        clear_screen();
        std::cout << "Type your new player name(Do '_' instead of space)" << std::endl;
        std::cin >> new_name;
        data.player.set_name(new_name);
        data.player.clear_monsters();
        data.player.add_monster(Monster("horse1", 4, 1));
        data.player.add_monster(Monster("horse2", 4, 1));
        data.player.add_monster(Monster("none", 0, 0));
        data.player.add_monster(Monster("none", 0, 0));
        break;
    
    case LEAVE_CHAR_CREATION:
        return START;


    default:
        std::cout << "sumting wong" << std::endl;
        break;
    }
    
    return START;
}
