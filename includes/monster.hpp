#ifndef MONSTER_H
#define MONSTER_H
#include <iostream>


class Monster{
    private:
    

    public:
    Monster();
    Monster(std::string, int, int);
    ~Monster();
    std::string name;
    int hp;
    int damage;
    int lvl;
    void abandon();

};

#endif