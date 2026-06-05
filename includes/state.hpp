#ifndef STATE_H
#define STATE_H

class State{
    private:


    public:
    virtual ~State() = default;
    virtual void on_entry() = 0;
    virtual int evaluate_user_input(int) = 0;
};

#endif