#ifndef DIRECTION_H
#define DIRECTION_H

#include <string>
#include <cassert>
#include <iostream>
#include "Random.h"

class Direction {
public:
    enum Dir {
        up,
        left,
        down,
        right,
        max_directions,
    };
private:
    Dir m_direction {};
public:
    Direction(char command);
    Direction(Dir direction): m_direction {direction} {}
    Dir direction() const {return m_direction;}
    Direction operator-() const;
    
    static Direction randomDirection();


    friend std::ostream& operator<< (std::ostream& out, Direction::Dir direction);
    friend std::ostream& operator<< (std::ostream& out, const Direction& direction);

};

Direction::Direction(char command)
{
    switch(command) {
        case 'w':
            m_direction = up;
            break;
        case 'a':
            m_direction = left;
            break;
        case 's':
            m_direction = down;
            break;
        case 'd':
            m_direction = right;
            break;
        default:
            assert(false && "Invalid input to Direction Constructor");
    }
}

Direction Direction::randomDirection() {
    return Direction {static_cast<Dir>(Random::get(0, max_directions - 1))};
}

Direction Direction::operator-() const{
    switch(m_direction) {
        case up:
            return Direction{down};
        case left:
            return Direction{right};
        case down:
            return Direction{up};
        case right:
            return Direction{left};
        default:
            assert(0 && "Unsupported direction was passed!");
            return Direction{left};
    }
}

std::ostream& operator<< (std::ostream& out, Direction::Dir direction) {
    switch(direction) {
        case Direction::up:
            out << "up";
            break;
        case Direction::left:
            out << "left";
            break;
        case Direction::down:
            out << "down";
            break;
        case Direction::right:
            out << "right";
            break;
        default:
            out << "Unknown Direction";
            break;

    }
    return out;
}

std::ostream& operator<< (std::ostream& out, const Direction& direction) {
    out << direction.m_direction;
    return out;
}

#endif