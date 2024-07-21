#include <cstdint>
#include <string>
#include <iostream>
#include <cmath>
#include "FixedPoint2.h"


FixedPoint2::FixedPoint2(std::int16_t whole, std::int8_t fractional)
    : m_whole {whole}
    , m_fractional {fractional}
{
    if(m_whole > 0 && +m_fractional < 0) {
        m_whole *= -1;
    } else if(m_whole < 0 && +m_fractional > 0) {
        m_fractional *= -1;
    }

    m_whole += m_fractional / 100;
    m_fractional %= 100;
}

FixedPoint2::FixedPoint2(double val):
    FixedPoint2(
        static_cast<std::int16_t>(val),
        static_cast<std::int8_t>(std::round((val - static_cast<int>(val)) * 100))
    )
{
}

FixedPoint2::operator double() const {
    return m_whole + (+m_fractional / 100.0);
}

std::ostream& operator<< (std::ostream& out, FixedPoint2& num) {
    out << static_cast<double>(num);
    return out;
}

std::istream& operator>> (std::istream& in, FixedPoint2& num) {
    double val {};
    in >> val;
    if(in) {
        num = FixedPoint2{val};
    }
    return in;
}


FixedPoint2 FixedPoint2::operator-() {
	return FixedPoint2
	{
		static_cast<std::int16_t>(-1 * m_whole),
		static_cast<std::int8_t>(-1 * m_fractional)
	};
}

bool operator==(const FixedPoint2& first, const FixedPoint2& second) {
    return (first.m_whole == second.m_whole) && (first.m_fractional == second.m_fractional);
}

FixedPoint2 operator+(const FixedPoint2& first, const FixedPoint2& second) {
    return FixedPoint2 {static_cast<double>(first) + static_cast<double>(second)};
}

