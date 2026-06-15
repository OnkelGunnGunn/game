#include "catch_state.hpp"

CatchState::CatchState(GameData &data) : data(data)
{
}

void CatchState::on_entry()
{
    clear_screen();

    if (!data.can_catch)
    {
        std::cout << "No monster to catch!" << std::endl;
        return;
    }

    std::cout << "You defeated a monster!" << std::endl;
    std::cout << "Do you want to catch: "
              << data.loot_monster.name << "?" << std::endl;

    std::cout << "1. Catch" << std::endl;
    std::cout << "2. Leave it" << std::endl;
}

int CatchState::evaluate_user_input(int input)
{
    auto& monsters = data.player.get_all_monsters();

    switch (input)
    {
    case CATCH_MONSTER:
    {
        if (monsters.size() < 4)
        {
            monsters.push_back(data.loot_monster);

            std::cout << data.loot_monster.name
                      << " was added to your team!" << std::endl;
        }
        else
        {
            std::cout << "Your team is full!" << std::endl;
            std::cout << "Choose a monster to replace:" << std::endl;

            for (int i = 0; i < monsters.size(); ++i)
            {
                std::cout << i << ". "
                          << monsters[i].name
                          << " (HP: " << monsters[i].hp << " DMG: " << monsters[i].damage << ")" << std::endl;
            }

            int choice;
            std::cin >> choice;

            if (choice >= 0 && choice < monsters.size())
            {
                std::cout << monsters[choice].name
                          << " was replaced by "
                          << data.loot_monster.name << "!" << std::endl;

                monsters[choice] = data.loot_monster;
            }
        }

        data.can_catch = false;
        return START;
    }

    case DONT_CATCH: // Leave
        data.can_catch = false;
        return START;

    default:
        return CATCH;
    }
}

