#ifndef POTION_H
#define POTION_H

#include <iostream>
#include "Random.h"

class Potion {
public:
    enum Type {
        health,
        strength,
        poison,
        maxType,
    };

    enum Size {
        small,
        medium,
        large,
        maxSize,
    };

    struct potionEffect {
        int healthChange {};
        int strengthChange {};
    };

    Potion(Type type, Size size) 
        : m_type {type}
        , m_size {size}
    {}

    Type getType() {return m_type;}
    Size getSize() {return m_size;}

    static Potion getRandomPotion() {
        return Potion {static_cast<Type>(Random::get(0, maxType - 1)), static_cast<Size>(Random::get(0, maxSize - 1))};
    }

    static potionEffect getPotionEffects(const Potion& potion) {
        return potionEffects[static_cast<int>(potion.m_type) * 3 + static_cast<int>(potion.m_size)];
    }

    friend std::ostream& operator<< (std::ostream& out, Type type) {
        switch(type) {
            case health:
                out << "Health";
                break;
            case strength:
                out << "Strength";
                break;
            case poison:
                out << "Poison";
                break;
            default:
                out << "?????";
        }
        return out;
    }

    friend std::ostream& operator<< (std::ostream& out, Size size) {
        switch(size) {
            case small:
                out << "Small";
                break;
            case medium:
                out << "Medium";
                break;
            case large:
                out << "Large";
                break;
            default:
                out << "?????";
        }
        return out;
    }

private:
    Type m_type {};
    Size m_size {};

    static inline potionEffect potionEffects[] {
        {1, 0},
        {3, 0},
        {5, 0},
        {0, 1},
        {0, 2},
        {0, 3},
        {-1, 0},
        {-2, 0},
        {-3, 0}
    };
};

#endif