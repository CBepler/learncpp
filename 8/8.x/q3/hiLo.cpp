#include <iostream>
#include "Random.h"

namespace Constants{
    constexpr int maxTries{7};
}

int getGuess(){
    std::cout << "Enter guess: ";
    int guess{};
    std::cin >> guess;
    return guess;
}

bool gameOutcome(int correct){
    for(int i{0}; i < Constants::maxTries; ++i){
        int guess = getGuess();
        if(guess > correct){
            std::cout << "Lower\n";
        }
        else if(guess < correct){
            std::cout << "Higher\n";
        }
        else{
            return true;
        }
    }
    return false;
}

void playGame(){
    int correct = Random::get(1, 100);
    bool outcome = gameOutcome(correct);
    if(outcome){
        std::cout << "You win\n";
    }
    else{
        std::cout << "You Lose\n";
        std::cout << "The correct answer was: " << correct << '\n';
    }
}

bool askPlay(){
    while(true){
        std::cout << "would you like to play again? (y/n): ";
        char ans{};
        std::cin >> ans;
        if(ans == 'y'){
            return true;
        }
        else if(ans == 'n'){
            return false;
        }
    }
}

int main()
{
    bool playAgain{true};
    while(playAgain){
        playGame();
        playAgain = askPlay();
    }
    return 0;
}
