#ifndef NPC_HPP
#define NPC_HPP
#include "monster.hpp"
#include <vector>
#include <iostream>


class Npc{
    private:
    std::string name;
    std::vector<Monster> monsters;


    public:
    Npc();
    Npc(const std::string& input_name);
    void add_monster(const Monster& m);
    void print_monsters() const;
    std::string get_name() const;


};





#endif