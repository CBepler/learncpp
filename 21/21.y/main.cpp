#include <iostream>
#include <limits>
#include <cassert>
#include "Board.h"
#include "Direction.h"
#include "Point.h"

namespace UserInput {
    char getInput() {
        char in {};
        while(true) {
            std::cin >> in;
            if(!std::cin) {
                std::cin.clear();
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if(in == 'w' || in == 'a' || in == 's' || in == 'd' || in == 'q') {
                break;
            }
        }
        return in;
    }

    Direction makeDirection(char in) {
        assert(in == 'w' || in == 'a' || in == 's' || in == 'd');
        return Direction {in};
    }
}

// int main()
// {
//     std::cout << std::boolalpha;
//     std::cout << (Point{ 1, 1 }.getAdjacentPoint(Direction::up)    == Point{ 1, 0 }) << '\n';
//     std::cout << (Point{ 1, 1 }.getAdjacentPoint(Direction::down)  == Point{ 1, 2 }) << '\n';
//     std::cout << (Point{ 1, 1 }.getAdjacentPoint(Direction::left)  == Point{ 0, 1 }) << '\n';
//     std::cout << (Point{ 1, 1 }.getAdjacentPoint(Direction::right) == Point{ 2, 1 }) << '\n';
//     std::cout << (Point{ 1, 1 } != Point{ 2, 1 }) << '\n';
//     std::cout << (Point{ 1, 1 } != Point{ 1, 2 }) << '\n';
//     std::cout << !(Point{ 1, 1 } != Point{ 1, 1 }) << '\n';

//     return 0;
// }

int main()
{
    Board board{};
    board.randomizeBoard();
    std::cout << board;


    for(int i {0}; i < 4; ++i) {
        std::cout << "Generating random direction... " << Direction::randomDirection() << '\n';
    }

    std::cout << "\nEnter a command: ";
    char in {};
    while(true){
        in = UserInput::getInput();
        if(in == 'q'){break;}
        Direction dir {in};
        std::cout << "You entered direction: " << dir << '\n';
        if(board.moveTile(dir)) {
            std::cout << board;
        }
        if(board.checkWin()) {
            std::cout << "\n\nYOU WIN\n\n";
            break;
        }
    }
    
    std::cout << "\n\nBye!\n\n";

    return 0;
}