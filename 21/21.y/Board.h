#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <iostream>
#include <utility>
#include "Tile.h"
#include "Direction.h"
#include "Point.h"

class Board {
public:
    Board() = default;

    static void printEmptyLines(int count)
    {
        for (int i = 0; i < count; ++i)
            std::cout << '\n';
    }

    bool moveTile(const Direction& direction);
    void randomizeBoard();
    bool checkWin();

    Point findEmpty() const;
    static bool checkValidity(const Point& point);


    friend std::ostream& operator<< (std::ostream& out, Board& board);
private:
    static constexpr int randomizationFactor {1000};
    static constexpr int consoleLines {25};
    static constexpr int SIZE {4};
    Tile m_tiles[SIZE][SIZE]{
        Tile{ 1 }, Tile { 2 }, Tile { 3 } , Tile { 4 },
        Tile { 5 } , Tile { 6 }, Tile { 7 }, Tile { 8 },
        Tile { 9 }, Tile { 10 }, Tile { 11 }, Tile { 12 },
        Tile { 13 }, Tile { 14 }, Tile { 15 }, Tile { 0 } };
};

std::ostream& operator<< (std::ostream& out, Board& board) {
        board.printEmptyLines(board.consoleLines);

        for (int y = 0; y < board.SIZE; ++y)
        {
            for (int x = 0; x < board.SIZE; ++x)
                out << board.m_tiles[y][x];
            out << '\n';
        }
        return out;
}

Point Board::findEmpty() const{
    for(int i {0}; i < SIZE; ++i) {
        for(int j {0}; j < SIZE; ++j) {
            if(m_tiles[i][j].isEmpty()) {
                return Point {j, i};
            }
        }
    }
    return Point {-1, -1};
}

bool Board::checkValidity(const Point& point) {
    return point.x() >= 0 && point.x() < SIZE && point.y() >= 0 && point.y() < SIZE;
}

bool Board::moveTile(const Direction& direction) {
    Point empty {findEmpty()};
    Point mover {empty.getAdjacentPoint((-direction).direction())};
    bool isValidPoint {checkValidity(mover)};
    if(!isValidPoint) {
        return false;
    }
    std::swap(m_tiles[empty.y()][empty.x()], m_tiles[mover.y()][mover.x()]);
    return true;
}

void Board::randomizeBoard() {
    for(int i{0}; i < randomizationFactor; ++i) {
        bool success {moveTile(Direction::randomDirection())};

        if(!success) {
            --i;
        }
    }
}

bool Board::checkWin() {
    for(int i {0}; i < SIZE; ++i) {
        for(int j {0}; j < SIZE; ++j) {
            if(i == 3 && j == 3 && m_tiles[i][j].getNum() == 0) {
                return true;
            }
            if(!(m_tiles[i][j].getNum() == (i * 4) + (j + 1))) {
                return false;
            }
        }
    }
    return true;
}

#endif