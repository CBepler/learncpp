#include <string>
#include <string_view>
#include <cassert>

class MyString {
private:
    std::string m_string {};
public:
    MyString(std::string_view s)
        : m_string{s}
    {}

    std::string_view operator() (int start, int length);
    friend std::ostream& operator<<(std::ostream& out, const MyString& string);
};

std::ostream& operator<<(std::ostream& out, const MyString& string) {
    out << string.m_string;
    return out;
}

std::string_view MyString::operator() (int start, int length) {
    assert(start >= 0);
    return std::string_view{m_string}.substr(static_cast<std::string_view::size_type>(start), static_cast<std::string_view::size_type>(length));
}