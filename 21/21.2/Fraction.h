#include <iostream>
#include <numeric>

class Fraction {
private:
    int m_numerator {};
    int m_denominator {1};
public:
    explicit Fraction(int numerator, int denominator = 1)
        : m_numerator {numerator}
        , m_denominator {denominator}
    {
        reduce();
    }
    void print() {
        std::cout << m_numerator << "/" << m_denominator << '\n';
    }

    void reduce() {
        int gcd {std::gcd(m_numerator, m_denominator)};
        if(gcd) {
            m_numerator /= gcd;
            m_denominator /= gcd;
        }
    }

    friend Fraction operator*(const Fraction& f1, const Fraction& f2) {
        return Fraction {f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator};
    }

    friend Fraction operator*(const Fraction& f, int x) {
        return Fraction {f.m_numerator * x, f.m_denominator};
    }

    friend Fraction operator*(int x, const Fraction& f) {
        return f * x;
    }
};