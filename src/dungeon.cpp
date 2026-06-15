#include "dungeon.hpp"

Dungeon::Dungeon() : current_enemy_index(0) {}

void Dungeon::add_enemy(const Npc& npc)
{
    enemies.push_back(npc);
}

Npc& Dungeon::get_current_enemy()
{
    return enemies[current_enemy_index];
}

void Dungeon::next_enemy()
{
    current_enemy_index++;
}

bool Dungeon::is_finished() const
{
    return current_enemy_index >= enemies.size();
}
