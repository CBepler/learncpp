#include "Random.h"
#include "Session.h"
#include <iostream>
#include <vector>
#include <string_view>

namespace WordList {
    using namespace std::string_view_literals;
    std::vector words {"mystery"sv, "broccoli"sv , "account"sv, "almost"sv, "spaghetti"sv, "opinion"sv, "beautiful"sv, "distance"sv, "luggage"sv};

        std::string_view getRandomWord() {
        return words[Random::get<std::size_t>(0, static_cast<int>(words.size()) - 1)];
    }
}

int main()
{
    std::cout << "Welcome to C++man (a variant of Hangman)\n";
    std::cout << "To win: guess the word.  To lose: run out of pluses.\n";
    std::cout << '\n';
    std::string_view ans {WordList::getRandomWord()};
    std::cout << "The word is: " << ans << '\n';
    Session session {ans};
    while(!session.displayState()) {
        session.getInput();
    }
    return 0;
}
