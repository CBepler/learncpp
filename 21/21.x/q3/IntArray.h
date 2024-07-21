#include <utility>
#include <cassert>
#include <iostream>

class IntArray {
private:
    int m_length {0};
    int* m_arr {nullptr};
public:
    IntArray(int length)
        : m_length {length}
        , m_arr {new int[length]}
    {
        assert(length > 0);
    }

    IntArray(const IntArray& in) 
        :m_length {in.m_length}
    {
        m_arr = new int[m_length];
        for(int i {0}; i < m_length; ++i) {
            m_arr[i] = in.m_arr[i];
        }
    }

    ~IntArray() {
        delete[] m_arr;
    }

    friend void swap(IntArray& first, IntArray& second) {
        std::swap(first.m_length, second.m_length);
        std::swap(first.m_arr, second.m_arr);
    }

    IntArray& operator=(IntArray in) {
        swap(*this, in);
        return *this;
    } 

    int& operator[] (int index) {
        assert(index >= 0 && index < m_length);
        return m_arr[index];
    }

    friend std::ostream& operator<< (std::ostream& out, const IntArray& in) {
        for(int i {0}; i < in.m_length; ++i) {
            if(i != 0) {
                out << ' ';
            }
            out << in.m_arr[i];
        }
        return out;
    }



};