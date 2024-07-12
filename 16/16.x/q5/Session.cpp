#include "Session.h"
#include <iostream>
#include <limits>
#include <vector>

bool Session::displayState() const {
    if(m_lives < 1) {
            std::cout << "Game over";
            return true;
     }
    std::cout << "The word: ";
    bool won {true};
    for([[maybe_unused]]const auto& letter : m_ans) {
        if(m_guesses[(letter % 32) - 1]) {
            std::cout << letter;
        } else {
            std::cout << "_";
            won = false;

        }
    }
    std::cout << "\t" << m_lifeView << '\n';
    std::cout << '\n';
    if(won) {
        std::cout << "You Win\n";
        return true;
    }
    return false;
}

void Session::getInput() {
    char x {};
    while(true) {
        std::cout << "Enter your next letter: ";
        std::cin >> x;

        if (!std::cin || (x < 'a' || x > 'z')) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "That wasn't a valid input.  Try again.\n";
            continue;
        }

        if(m_guesses[(x % 32) - 1]) {
            std::cout << "You already guessed that. Try Again.\n";
            continue;
        }
        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        m_guesses[(x % 32) - 1] = true;

        bool present {false};
        for([[maybe_unused]]const auto& letter : m_ans) {
            if (x == letter) {
                present = true;
            }
        }

        if(!present) {
            m_lives -= 1;
            m_lifeView[m_lives] = x;
        }
    
        break;
    }
    std::cout << "You entered: " << x << '\n';
}