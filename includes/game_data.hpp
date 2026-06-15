#ifndef GAMEDATA_HPP
#define GAMEDATA_HPP

#include <string>
#include <vector>
#include "monster.hpp"
#include "player.hpp"
#include "npc.hpp"
#include "item.hpp"

struct GameData {
    Player player;
    Npc current_enemy;
    Monster loot_monster;
    bool can_catch = false;

    Item item_reward;

    BattleType battle_type;
};

#endif
