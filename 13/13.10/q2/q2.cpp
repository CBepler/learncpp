#include <iostream>

struct Fraction {
    int numerator {};
    int denominator {};
};

Fraction getFraction() {
    std::cout << "Enter Fraction (a/b): ";
    Fraction fraction {};
    std::cin >> fraction.numerator;
    char temp {};
    std::cin >> temp;
    std::cin >> fraction.denominator;
    return fraction;
}

Fraction operator*(const Fraction& a, const Fraction& b) {
    return {a.numerator * b.numerator, a.denominator * b.denominator};
}

std::ostream& operator<<(std::ostream& out, const Fraction& fraction) {
    return out << fraction.numerator << "/" << fraction.denominator;
}

int main()
{
    Fraction fractionA {getFraction()};
    Fraction fractionB {getFraction()};

    std::cout << fractionA * fractionB;

    return 0;
}
