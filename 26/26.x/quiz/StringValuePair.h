#ifndef STRING_VALUE_PAIR_H
#define STRING_VALUE_PAIR_H

#include <string>
#include <string_view>
#include "Pair.h"

template <typename T>
class StringValuePair : public Pair<std::string, T> {
public:
    StringValuePair(std::string_view first, const T& second)
        : Pair<std::string, T> {static_cast<std::string>(first), second}
    {}
};

#endif