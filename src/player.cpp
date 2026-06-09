#include "player.hpp"

Player::Player() : name("Default Player")
{
}

void Player::set_name(std::string &new_name)
{
    name = new_name;
}

std::string Player::get_name() const
{
    return std::string(name);
}

std::vector<Monster> &Player::get_monsters()
{
    return monsters;
}

void Player::add_monster(const Monster &m)
{
}
