#include <vector>
#include <iostream>

int getValues() {
    std::cout << "Enter an integer: ";
    int value {};
    std::cin >> value;
    return value;
}

int main()
{
    std::vector<int> values (3);
    // for(int i = 0; i < values.size(); ++i) {
    //     values[i] = getValues();
    // }
    std::cout << "Enter 3 integers: ";
    std::cin >> values[0] >> values[1] >> values[2];
    int sum {};
    int product {1};
    for(int i = 0; i < values.size(); ++i) {
        sum += values[i];
        product *= values[i];
    }
    std::cout << "The sum is " << sum << '\n';
    std::cout << "The product is " << product << '\n';
    return 0;
}
