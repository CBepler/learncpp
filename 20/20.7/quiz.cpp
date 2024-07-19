#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>
#include <cmath>
#include "Random.h"

namespace config {
    constexpr int multiplierMin {2};
    constexpr int multiplierMax {4};
}

int getInt() {
    int val {};
    while(true) {
        std::cin >> val;
        if(!std::cin) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter a valid integer\n";
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return val;
    }
}

int getPosotiveInt() {
    int val {getInt()};
    while(val < 0) {
        std::cout << "Enter a posotive value: ";
        val = getInt();
    }
    return val;
}

std::vector<int> makeMultipliedSquares(int start, int count, int multiplier) {
    std::vector<int> squares (count);
    for(int i {start}; i < start + count; ++i) {
        squares[static_cast<std::size_t>(i - start)] = i * i * multiplier;
    }
    return squares;
}

int main()
{
    std::cout << "Start where? ";
    int start {getInt()};

    std::cout << "How many? ";
    int count {getPosotiveInt()};

    int multiplier {Random::get(config::multiplierMax, config::multiplierMax)};
    std::vector squares {makeMultipliedSquares(start, count, multiplier)};

    std::cout << "I generated " << count << " square numbers. Do you know what each number is after multiplying it by "<< multiplier << "?\n";

    while (true) {
        int guess {getInt()};

        auto found {std::find(squares.begin(), squares.end(), guess)};

        if(found == squares.end()) {
            auto closestAns {std::min_element(squares.begin(), squares.end(), [=](int ans1, int ans2) {
                                return std::abs(ans1 - guess) < std::abs(ans2 - guess);
                            })};
            std::cout << guess << " is wrong! Try " << *closestAns << " next time.\n";
            break;
        } else {
            squares.erase(found);
            --count;
            if(count < 1) {
                std::cout << "Nice! You found all numbers, good job!\n";
                break;
            } else {
                std::cout << "Nice! " << count << " numbers left.\n";
            }
        }
    }

    return 0;
}
