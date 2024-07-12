#include <iostream>
#include <vector>
#include <cassert>

namespace Animals {
    enum Animals{
        chicken,
        dog,
        cat,
        elephant,
        duck,
        snake,
        maxAnimals,
    };
}

int main()
{
    const std::vector legs {2, 4, 4, 4, 2, 0};
    assert(legs.size() == Animals::maxAnimals);
    std::cout << "An elephant has " << legs[Animals::elephant] << " legs\n";
    return 0;
}
