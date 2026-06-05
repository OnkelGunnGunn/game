#ifndef STATE_H
#define STATE_H

enum MenuState{
    START,
    EXPLORE,
    BATTLE,
    INVENTORY,
    MONSTER_DETAILS1,
    MONSTER_DETAILS2,
    MONSTER_DETAILS3,
    MONSTER_DETAILS4,
    RENAME,
    CREATE_CHAR,
    LEAVE,


};

class State{
    private:


    public:
    virtual ~State() = default;
    virtual void on_entry() = 0;
    virtual int evaluate_user_input(int) = 0;
};

#endif