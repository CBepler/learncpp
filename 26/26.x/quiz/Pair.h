#ifndef PAIR_H
#define PAIR_H

template<typename T, typename U>
class Pair {
private:
    T m_first {};
    U m_second {};
public:
    Pair(const T& first, const U& second)
        : m_first {first}
        , m_second {second}
    {}

    const T& first() const {return m_first;}
    const U& second() const {return m_second;}

};

#endif