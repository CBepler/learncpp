#include <iostream>
#include "Random.h"
#include <cassert>


namespace Constants{
    constexpr int maxTries{7};
}

void ignoreLine(){
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool clearFailedExtraction(){
    if(!std::cin){
        if(std::cin.eof()){
            exit(0);
        }

        std::cin.clear();
        ignoreLine();

        return true;
    }
    else{
        return false;
    }
}

int getGuess(){
    while(true){
        std::cout << "Enter guess: ";
        int guess{};
        std::cin >> guess;
        ignoreLine();

        if(clearFailedExtraction() || guess <= 0 || guess > 100){
            std::cerr << "Error: Invalid input, Try Again\n";
            continue;
        }

        return guess;
    }
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
    std::cout << "Try to guess the number that is between 1 and 100 inclusive\n";
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
        ignoreLine();
        assert(!(clearFailedExtraction()));
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
