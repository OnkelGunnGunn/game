#ifndef EXPLORE_STATE_HPP
#define EXPLORE_STATE_HPP

#include "state.hpp"
#include "monster.hpp"
#include "game_data.hpp"
#include "npc.hpp"

enum ExploreOptions{
    WILD_ENCOUNTER1 = 1,
    WILD_ENCOUNTER2 = 2,
    WILD_ENCOUNTER3 = 3,
    EXIT_EXPLORE = 4,
};

struct MonsterSpawnRates{
    Monster monster;
    int weight;
};


class ExploreState : public State{

    private:
    GameData& data;
    std::vector<Monster> wild_monster;
    Monster encountered_monster;
    


    public:
    ExploreState(GameData& data);
    void on_entry() override;
    int evaluate_user_input(int) override;
    Monster get_monster() const;
    Monster weighted_random_monster();
    void generate_random_encounters();



};



#endif