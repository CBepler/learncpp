#include <iostream>
#include <array>
#include <string>
#include <limits>

namespace Animal {
    enum Type {
        chicken,
        dog,
        cat,
        elephant,
        duck,
        snake,
        maxAnimals,
    };

    struct Data {
        std::string name {};
        int numLegs {};
        std::string sound {};
    };

    std::array data {
        Data {"chicken", 2, "cluck"},
        Data {"dog", 4, "bark"},
        Data {"cat", 4, "meow"},
        Data {"elephant", 4, "kys"},
        Data {"duck", 2, "quack"},
        Data {"snake", 0, "sssssssss"},
    };
    static_assert(std::size(data) == maxAnimals);
}

std::istream& operator>>(std::istream& in, Animal::Data& animal) {
    std::string input {};
    std::getline(in >> std::ws, input);
    for(const auto& e : Animal::data) {
        if(e.name == input) {
            animal = e;
            return in;
        }
    }

    in.setstate(std::ios_base::failbit);
    animal = {};
    return in;
}

void printAnimalData(const Animal::Data& animal) {
    if(animal.name == "") {
        std::cout << "That animal couldn't be found.\n";
    } else {
        std::cout << "A " << animal.name << " has " << animal.numLegs << " legs and says " << animal.sound << ".\n";
    }
    std::cout << '\n';
    std::cout << "Here is the data for the rest of the animals:\n";
    for(const auto& e : Animal::data) {
        if(e.name == animal.name)
            continue;
        std::cout << "A " << e.name << " has " << e.numLegs << " legs and says " << e.sound << ".\n";
    }
}

int main()
{
    std::cout << "enter an animal: ";
    Animal::Data animal {};
    std::cin >> animal;
    if(!std::cin) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    printAnimalData(animal);
    return 0;
}
