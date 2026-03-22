#include "monster.hpp"

Monster::Monster()
{
    this->name = "none";
    this->hp = 0;
    this->damage = 0;
}

Monster::Monster(std::string name, int hp, int damage)
{
    this->name = name;
    this->hp = hp;
    this->damage = damage;
}

Monster::~Monster()
{
}

void Monster::abandon()
{
    this->name = "none";
    this->hp = 0;
    this->damage = 0;
}
