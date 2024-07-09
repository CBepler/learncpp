#include <iostream>

template <typename T, typename U, typename V>
class Triad {
public:
    Triad(const T& x, const U& y, const V& z) 
        : m_x {x}
        , m_y {y}
        , m_z {z}
    {
    }

    const T& first() const {return m_x;}
    const U& second() const {return m_y;}
    const V& third() const {return m_z;}

    void print() const;

private:
    T m_x {};
    U m_y {};
    V m_z {};
};

template <typename T, typename U, typename V>
void Triad<T, U, V>::print() const {
    std::cout << "[" << m_x << ", " << m_y << ", " << m_z << "]\n";
}