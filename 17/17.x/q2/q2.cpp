#include "Player.h"
#include <iostream>
#include <string_view>
#include <array>
#include <string>
#include <limits>

namespace Constants {
    constexpr int asciiAlign {48};
    constexpr int exitValue {65};
}

namespace Potion {
    enum Type {
        healing,
        mana,
        speed,
        invisibility,
        maxType,
    };

    constexpr std::array types {healing, mana, speed, invisibility};
    constexpr std::array costs {20, 30, 12, 50};
    constexpr std::array<std::string_view, maxType> names {"healing", "mana", "speed", "invisibility"};

    static_assert(types.size() == maxType);
    static_assert(costs.size() == maxType);
    static_assert(names.size() == maxType);
}

void shop() {
    std::cout << "Here is our selection for today:\n";
    for(const auto& e : Potion::types) {
        std::cout << e << ") " << Potion::names[e] << " costs " << Potion::costs[e] << '\n';
    }
}

int getInput() {
    while(true) {
        std::cout << "Enter the number of the potion you'd like to buy, or 'q' to quit: ";
        char in {};
        std::cin >> in;
        int input = static_cast<int>(in) - Constants::asciiAlign;
        if(!std::cin) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Please enter a valid input.\n";
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if(input != Constants::exitValue && (input < 0 || input >= Potion::maxType)) {
            std::cout << "Please enter a valid item number or q to exit\n";
            continue;
        }
        return input;
    }
}

void exit(const Player& player) {
    std::cout << "\nYour inventory contains:\n";
    for(int i {0}; i < Potion::maxType; ++i) {
        if(player.inventory()[i] == 0){continue;}
        std::cout << player.inventory()[i] << "x potion of " << Potion::names[i] << '\n';
    }
    std::cout << "You escaped with " << player.gold() << " gold remaining.\n";
}

void handleBuy(Player& player, int input) {
    if(!player.spendGold(Potion::costs[input])){
        std::cout << "You can't afford that.\n";
        return;
    }
    std::cout << "You purchased a potion of " << Potion::names[input] << '.';
    player.addToInventory(input);
    std::cout << "\tYou have " << player.gold() << " gold left.\n";
}

void handleInput(int input, Player& player) {
    if(input == Constants::exitValue) {
        exit(player);
        return;
    }
    handleBuy(player, input);
}

int main()
{
    std::cout << "Welcome to Roscoe's potion emporium!\n";
    std::cout << "Enter your name: ";
    std::string name {};
    std::getline(std::cin >> std::ws, name);
    Player player {name, Potion::maxType};
    std::cout << "Hello, " << player.name() << ", you have " << player.gold() << " gold.\n\n";
    char input {};
    do {
        shop();
        input = getInput();
        handleInput(input, player);
        std::cout << '\n';
    } while(input != Constants::exitValue);
    std::cout << "\nThanks for shopping at Roscoe's potion emporium!\n";
    return 0;
}