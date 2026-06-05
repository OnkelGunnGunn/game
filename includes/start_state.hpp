#ifndef START_STATE_H
#define START_STATE_H

#include "state.hpp"

class startState : public State{
    private:


    public:
    void on_entry() override;
    int evaluate_user_input(int) override;
};

#endif