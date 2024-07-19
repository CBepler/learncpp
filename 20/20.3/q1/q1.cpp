#include <iostream>
#include <vector>
#include <cassert>

int factorial(int val) {
    static std::vector facts {1};

    assert(val >= 0);

    if(val < std::size(facts)) {
        return facts[val];
    }

    facts.emplace_back(val * factorial(val - 1));
    return facts[val];
}

int main()
{
    int input {};
    do {
        std::cin >> input;
        std::cout << factorial(input) << '\n';
    }while(input >= 0);
    return 0;
}
