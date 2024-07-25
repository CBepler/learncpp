#include <iostream>
#include <string>
#include <limits>
#include <functional>
#include "Creature.h"
#include "Player.h"
#include "Monster.h"
#include "Random.h"
#include "Potion.h"

char getChoice(std::function<bool(char)> validInput) {
    char choice {};
    while (true) {
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if(validInput(choice)) {
            return choice;
        }
    }
}

void attackMonster(const Player& player, Monster& monster) {
    std::cout << "You hit the " << monster.getName() << " for " << player.getDamage() << " damage.\n";
    monster.reduceHealth(player.getDamage());
}

void attackPlayer(Player& player, const Monster& monster) {
    std::cout << "The " << monster.getName() << " hit you for " << monster.getDamage() << " damage.\n";
    player.reduceHealth(monster.getDamage());
    std::cout << "You have " << player.getHealth() << " health remaining.\n";
}

void fightMonster(Player& player) {
    Monster monster {Monster::getRandomMonster()};
    std::cout << "You have encountered a " << monster.getName() << " (" << monster.getSymbol() << ")\n";
    while (true) {
        std::cout << "(R)un or (F)ight: ";
        char choice {getChoice(std::function<bool(char)>([](char choice) {
            return choice == 'f' || choice == 'r';
        }))};
        if (choice == 'r') {
            int outcome {Random::get(1, 2)};
            if(outcome == 1) {
                std::cout << "You fleed successfully\n";
                return;
            }
            std::cout << "You failed to flee\n";
        } else {
            attackMonster(player, monster);
        }
        if(monster.isDead()) {
            std::cout << "You killed the " << monster.getName() << ".\n";
            player.levelUp();
            std::cout << "You are now level " << player.getLevel() << ".\n";
            std::cout << "You found " << monster.getGold() << " gold.\n";
            player.addGold(monster.getGold());
            std::cout << "You found a mythical potion! Do you want to drink it? [y/n]: ";
            char potionChoice {getChoice(std::function<bool(char)>([](char choice) {
                            return choice == 'y' || choice == 'n';
                        }))};
            if(potionChoice == 'y') {
                Potion potion {Potion::getRandomPotion()};
                std::cout << "You drank a " << potion.getSize() << " potion of " << potion.getType() << ".\n";
                player.drinkPotion(potion);
                std::cout << "Your health is now " << player.getHealth() << " and your damage is now " << player.getDamage() << ".\n";
            }
            return;
        }
        attackPlayer(player, monster);
        if(player.isDead()) {
            return;
        }
    }
}

int main()
{
    std::cout << "Enter your name: ";
    std::string name {};
    std::cin >> name;
    Player player {name};
    std::cout << "Welcome, " << player.getName() << '\n';
    do {
        fightMonster(player);
    } while(!player.isDead() && !player.hasWon());

    if(player.isDead()) {
        std::cout << "You died at level " << player.getLevel() << " and with " << player.getGold() << " gold.\n";
        std::cout << "Too bad you can't take it with you!\n";
    } else if(player.hasWon()) {
        std::cout << "You reached level " << player.getLevel() << " and won with " << player.getGold() << " gold\n";
        std::cout << "Enjoy your retirenment hero.\n";
    }

	return 0;
}