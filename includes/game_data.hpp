#ifndef GAMEDATA_HPP
#define GAMEDATA_HPP

#include <string>
#include <vector>
#include "monster.hpp"
#include "player.hpp"
#include "npc.hpp"
#include "item.hpp"
#include "dungeon.hpp"

struct GameData {
    Player player;
    Npc current_enemy;
    Monster loot_monster;
    bool can_catch = false;

    Dungeon current_dungeon;

    Item item_reward;
    bool has_reward = false;

    BattleType battle_type;
};

#endif
