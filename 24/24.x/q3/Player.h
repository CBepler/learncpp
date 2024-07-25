#ifndef PLAYER_H
#define PLAYER_H

#include <string_view>
#include "Creature.h"
#include "Potion.h"

class Player : public Creature {
public:
    Player(std::string_view name)
        : Creature(name, '@', 10, 1, 0)
        , m_level {1}
    {}

    int getLevel() const {return m_level;}

    void levelUp() {
        ++m_level;
        ++m_damage;
    }

    bool hasWon() const {return m_level >= 20;}

    void drinkPotion(const Potion& potion) {
        Potion::potionEffect effects {Potion::getPotionEffects(potion)};
        m_health += effects.healthChange;
        m_damage += effects.strengthChange;
    }
private:
    int m_level {1};
};


#endif