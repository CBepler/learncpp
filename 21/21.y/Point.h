#ifndef POINT_H
#define POINT_H

#include <cassert>
#include "Direction.h"

class Point {
private:
    int m_x {0};
    int m_y {0};
public:
    Point(int x = 0, int y = 0)
        : m_x {x}
        , m_y {y}
    {}

    Point getAdjacentPoint(Direction::Dir direction);

    int x() const {return m_x;}
    int y() const {return m_y;}

    friend bool operator==(const Point& p1, const Point& p2);
    friend bool operator!=(const Point& p1, const Point& p2);
};

bool operator==(const Point& p1, const Point& p2) {
    return (p1.m_x == p2.m_x) && (p1.m_y == p2.m_y);
}

bool operator!=(const Point& p1, const Point& p2) {
    return !(p1 == p2);
}

Point Point::getAdjacentPoint(Direction::Dir direction) {
    switch(direction) {
        case(Direction::up): return Point {m_x , m_y - 1};
        case(Direction::left): return Point {m_x - 1, m_y};
        case(Direction::down): return Point {m_x, m_y + 1};
        case(Direction::right): return Point {m_x + 1, m_y};
        default:
            assert(false && "Invalid direction input");
            return Point {m_x, m_y};
    }
}

#endif
