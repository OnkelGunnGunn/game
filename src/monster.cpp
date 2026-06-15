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

void Monster::add_status(const Status& status)
{
    statuses.push_back(status);
}


void Monster::apply_statuses()
{
    for (auto& s : statuses)
    {
        s.apply(*this);
        s.decrease_duration();
    }

    // remove expired statuses
    statuses.erase(
        std::remove_if(statuses.begin(), statuses.end(),
            [](Status& s) { return s.is_expired(); }),
        statuses.end()
    );
}


void Monster::add_item(const Item& item)
{
    items.push_back(item);
}

std::vector<Item> &Monster::get_items()
{
    return items;
}
