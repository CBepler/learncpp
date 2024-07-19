#include <iostream>
#include <cmath>

void printBinary(unsigned int num) {
    if(num == 0) {
        return;
    }

    // if(num < 0) {
    //     printBinary(static_cast<int>(std::pow(2, 32)) + num);
    //     return;
    // }

    printBinary(num / 2);

    std::cout << num % 2;

}

int main()
{
    int x {};
    std::cout << "Enter an integer: ";
    std::cin >> x;

    printBinary(static_cast<unsigned int>(x));

    return 0;
}
