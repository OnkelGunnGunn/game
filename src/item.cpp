#include "item.hpp"
#include "monster.hpp"

Item::Item()
{
}

Item::Item(ItemType type) : type(type)
{
}

void Item::use(Monster &enemy)

{
    switch (type)
    {
    case ItemType::POISON:
        enemy.add_status(Status(StatusType::POISON, 3));
        break;

    case ItemType::STRENGTH_SAP:
        enemy.add_status(Status(StatusType::STRENGTH_SAP, 2));
        break;

    case ItemType::BOMB:
        enemy.hp -= 20;
        break;
    }
}

