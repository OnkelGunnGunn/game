#ifndef DUNGEON_HPP
#define DUNGEON_HPP

#include <vector>
#include "npc.hpp"

class Dungeon {
private:
    std::vector<Npc> enemies;
    int current_enemy_index;

public:
    Dungeon();

    void add_enemy(const Npc& npc);
    Npc& get_current_enemy();

    void next_enemy();
    bool is_finished() const;
};

#endif