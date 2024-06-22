#include <iostream>

constexpr bool isEven(int val){
    return (val % 2 == 0);
}



int main()
{
    std::cout << "Enter an integer: ";
    int val;
    std::cin >> val;
    std::cout << val << " is " << (isEven(val) ? "even" : "odd");
    return 0;
}
