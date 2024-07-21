#include <cstdint>  
#include <iostream>

class Average {
private:
    std::int32_t m_sum {0};
    std::int8_t m_numSeen {0};
public:
    Average(){}

    Average& operator+=(int num);
    friend std::ostream& operator<<(std::ostream& out, const Average& av);
};

Average& Average::operator+=(int num) {
    ++m_numSeen;
    m_sum += num;
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Average& av) {
    out << av.m_sum / static_cast<double>(av.m_numSeen);
    return out;
}
