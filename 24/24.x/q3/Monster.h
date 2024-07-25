#ifndef MONSTER_H
#define MONSTER

#include <string_view>
#include "Creature.h"
#include "Random.h"

class Monster : public Creature {
public:
    enum Type {
        dragon,
        orc,
        slime,
        maxTypes,
    };

    Monster(Type type)
        :Creature(monsterData[type])
    {}

    static Monster getRandomMonster() {
        return Monster {static_cast<Type>(Random::get(0, maxTypes - 1))};
    }
private:
    static inline Creature monsterData[] {
        {"dragon", 'D', 20, 4, 100},
        {"orc", 'o', 4, 2, 25},
        {"slime", 's', 1, 1, 10}
    };

    static_assert(std::size(monsterData) == maxTypes);
};

#endif