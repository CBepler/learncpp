#ifndef TILE_H
#define TILE_H

#include <iostream>

class Tile {
private:
    int m_value {};
public:
    Tile (int val)
    : m_value {val}
    {}

    Tile()
    : m_value {0}
    {}

    bool isEmpty() const {
        return m_value == 0;
    }

    int getNum() const {
        return m_value;
    }
};

std::ostream& operator<<(std::ostream& out, const Tile& t) {
    if(t.isEmpty()) {
        out << "    ";
        return out;
    }

    out << ((t.getNum() < 10) ? "  " : " ") << t.getNum() << " ";
    return out;
};

#endif