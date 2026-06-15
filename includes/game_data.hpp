#ifndef GAMEDATA_HPP
#define GAMEDATA_HPP

#include <string>
#include <vector>
#include <sqlite3.h>
#include "monster.hpp"
#include "player.hpp"
#include "npc.hpp"
#include "item.hpp"
#include "dungeon.hpp"
#include "state.hpp"

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

class Database_interface{
    private:
    sqlite3* db_handle;


    public:
    Database_interface();
    void init_db();
    void save_game_data(Player data);
    Player load_game_data(int game_id);
    std::vector<std::string> show_saved_games();


};


#endif
