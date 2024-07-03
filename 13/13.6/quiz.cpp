#include <iostream>
#include <string_view>

enum class Animal {
    pig,
    chicken,
    goat,
    cat,
    dog,
    duck,
};

constexpr std::string_view getAnimalName(Animal animal) {
    using enum Animal;
    switch(animal) {
        case pig: return "pig";
        case chicken: return "chicken";
        case goat: return "goat";
        case cat: return "cat";
        case dog: return "dog";
        case duck: return "duck";
        default: return "invalid";
    }
}

std::ostream& operator<<(std::ostream& out, Animal animal) {
    return out << getAnimalName(animal);
}

constexpr int printNumberOfLegs(Animal animal) {
    using enum Animal;
    switch(animal) {
        case pig:
        case goat:
        case cat:
        case dog:
            return 4;
        case chicken:
        case duck:
            return 2;
        default:
            return 0;
    }
}


int main()
{
    std::cout << "A " << Animal::cat << " has " << printNumberOfLegs(Animal::cat) << " legs";
    return 0;
}