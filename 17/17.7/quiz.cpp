#include <iostream>
#include <limits>

int main()
{
    constexpr int perfectSquares[] {0, 1, 4, 9};
    int input {};
    while(true) {
        std::cout << "Enter a single digit integer or -1 to quit: ";
        std::cin >> input;
        if(!std::cin || input < -1 || input >9) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Please enter a single digit positive integer\n";
            continue;
        }
        if(input == -1) {
            break;
        }
        bool found {false};
        for(const auto& e : perfectSquares) {
            if(e == input) {
                std::cout << input << " is a perfect square\n";
                found = true;
                break;
            }
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if(found) {continue;}
        std::cout << input << " is not a perfect square\n";
    }
    return 0;
}
