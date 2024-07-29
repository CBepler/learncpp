#include <iostream>
#include <exception>
#include "Fraction.h"

int main()
{
    std::cout << "Enter a numerator and denominator (n/d)";
    int numerator {};
    int denominator {};
    std::cin >> numerator;
    std::cin.ignore(1, '/');
    std::cin >> denominator;
    try {
        Fraction frac {numerator, denominator};
        std::cout << numerator << '/' << denominator << '\n';
    } catch (const std::exception& e) {
        std::cerr << e.what();
    }
    return 0;
}
