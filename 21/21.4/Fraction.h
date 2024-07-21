#include <iostream>
#include <numeric> // for std::gcd

class Fraction
{
private:
	int m_numerator{};
	int m_denominator{};

public:
	Fraction(int numerator=0, int denominator=1):
		m_numerator{numerator}, m_denominator{denominator}
	{
		// We put reduce() in the constructor to ensure any new fractions we make get reduced!
		// Any fractions that are overwritten will need to be re-reduced
		reduce();
	}

	void reduce()
	{
		int gcd{ std::gcd(m_numerator, m_denominator) };
		if (gcd)
		{
			m_numerator /= gcd;
			m_denominator /= gcd;
		}
	}

	friend Fraction operator*(const Fraction& f1, const Fraction& f2);
	friend Fraction operator*(const Fraction& f1, int value);
	friend Fraction operator*(int value, const Fraction& f1);
    friend std::ostream& operator<<(std::ostream& out, const Fraction& f);

	void print() const
	{
		std::cout << m_numerator << '/' << m_denominator << '\n';
	}
};

std::istream& operator>>(std::istream& in, Fraction& f);