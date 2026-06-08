#ifndef STATE_H
#define STATE_H

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
    virtual ~State() = default;
    virtual void on_entry() = 0;
    virtual int evaluate_user_input(int) = 0;
};

#endif