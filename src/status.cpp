#include "status.hpp"
#include "monster.hpp"

Status::Status(StatusType type, int duration) : type(type), duration(duration)
{
}


void Status::apply(Monster& target)
{
    switch (type)
    {
    case StatusType::POISON:
        target.hp -= 1;
        std::cout << target.name << " takes poison damage!" << std::endl;
        break;

    case StatusType::STRENGTH_SAP:
        target.damage = std::max(0, target.damage - target.damage / 2);
        std::cout << target.name << " loses strength!" << std::endl;
        break;

    default:
        break;
   
    }
}

void Status::decrease_duration()
{
    duration--;
}

bool Status::is_expired() const
{
    return duration <= 0;
}
