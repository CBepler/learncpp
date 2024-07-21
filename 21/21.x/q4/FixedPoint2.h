#ifndef FIXED_POINT2
#define FIXED_POINT2

#include <cstdint>
#include <iostream>
#include <functional>

class FixedPoint2 {
private:
    std::int16_t m_whole {0};
    std::int8_t m_fractional {0};
public:
    FixedPoint2(std::int16_t whole = 0, std::int8_t fractional = 0);
    FixedPoint2(double val);

    friend bool operator==(const FixedPoint2& first, const FixedPoint2& second);

    friend FixedPoint2 operator+(const FixedPoint2& first, const FixedPoint2& second);

    FixedPoint2 operator-();

    explicit operator double() const;

};

std::istream& operator>> (std::istream& in, FixedPoint2& num);
std::ostream& operator<< (std::ostream& out, FixedPoint2& num);


#endif