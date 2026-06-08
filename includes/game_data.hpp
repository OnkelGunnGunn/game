#ifndef GAMEDATA_HPP
#define GAMEDATA_HPP

#include <string>
#include <vector>
#include "monster.hpp"

struct GameData {
    std::string player_name;
    std::vector<Monster> monsters;
};

#endif
