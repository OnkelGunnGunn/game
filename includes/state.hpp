#ifndef STATE_HPP
#define STATE_HPP
#include <iostream>
#include <random>

enum States{
    START,
    EXPLORE,
    INVENTORY,
    CREATE_CHARACTER,
    SAVE,
    BATTLE,
    CATCH,
    REWARD,
    
    
    LEAVE,
}; // LEAVE SHALL ALWAYS BE LAST

enum BattleType{
    EXPLORATION,
    DUNGEON
};

class State{
    private:


    public:
    int rng(int, int);
    void clear_screen();
    void spacing();
    virtual ~State() = default;
    virtual void on_entry() = 0;
    virtual int evaluate_user_input(int) = 0;
};

#endif