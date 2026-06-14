#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include "monster.hpp"



class Player{

    private:
    std::string name;
    std::vector<Monster> monsters;


    public:
    Player();
    void set_name(std::string& new_name);
    std::string get_name() const;

    std::vector<Monster>& get_all_monsters();
    Monster& get_monster(int i);
    void add_monster(const Monster& m);
    void clear_monsters();

};








#endif