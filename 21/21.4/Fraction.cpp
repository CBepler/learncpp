#include "Fraction.h"

Fraction operator*(const Fraction& f1, const Fraction& f2)
{
	return Fraction { f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator };
}

Fraction operator*(const Fraction& f1, int value)
{
	return Fraction { f1.m_numerator * value, f1.m_denominator };
}

Fraction operator*(int value, const Fraction& f1)
{
	return Fraction { f1.m_numerator * value, f1.m_denominator };
}

std::ostream& operator<<(std::ostream& out, const Fraction& f) {
    out << f.m_numerator << "/" << f.m_denominator;
    return out;
}

std::istream& operator>>(std::istream& in, Fraction& f) {
    int numerator {};
    char divisor {};
    int denominator {};
    in >> numerator >> divisor >> denominator;
    if(in) {
        f = Fraction {numerator, denominator};
    }
    return in;
}
