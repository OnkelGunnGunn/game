#ifndef MONSTER_HPP
#define MONSTER_HPP
#include <iostream>
#include <vector>
#include "status.hpp"
#include "item.hpp"


class Monster{
    private:
    std::vector<Status> statuses;
    std::vector<Item> items;

    public:
    Monster();
    Monster(std::string, int, int);
    ~Monster();
    std::string name;
    int hp;
    int damage;
    int lvl;
    // struct item?
    // int challenge_rating
    void abandon();
    void add_status(const Status& status);
    void apply_statuses();
    void add_item(const Item& item);
    std::vector<Item>& get_items();

};

#endif