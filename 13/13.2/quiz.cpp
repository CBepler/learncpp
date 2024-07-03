#include <iostream>

namespace Monster 
{
    enum MonsterType 
    {
        orc,
        goblin,
        troll,
        ogre,
        skeleton,
    };
};

int main()
{
    Monster::MonsterType monster{Monster::troll};
    std::cout << monster;
    return 0;
}
