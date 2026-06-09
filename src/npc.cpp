#include "npc.hpp"

Npc::Npc(const std::string& input_name) : name(input_name)
{
}

void Npc::add_monster(const Monster &m)
{
    monsters.push_back(m);
}

void Npc::print_monsters() const
{
    for(const auto& m : monsters){
        std::cout << m.name << std::endl;
    }

}

std::string Npc::get_name() const
{
    return name;
}
