#ifndef STATE_H
#define STATE_H
#include <iostream>

enum MenuState{
    START,
    EXPLORE,
    BATTLE,
    INVENTORY,
    RENAME,
    CREATE_CHAR,
    LEAVE,


};

class State{
    private:


    public:
    void clear_screen();
    virtual ~State() = default;
    virtual void on_entry() = 0;
    virtual int evaluate_user_input(int) = 0;
};

#endif