#include <vector>
#include <cassert>
#include <iostream>
#include <string_view>
#include <type_traits>

namespace Items {
    enum Items: int {
        potions,
        torches,
        arrows,
        maxItems,
    };
}

int countTotalItems(const std::vector<int>& items) {
    int totalItems {};
    for(const auto& itemCount : items) {
        totalItems += itemCount;
    }
    return totalItems;
}

std::string_view getItemName(int itemCount, int itemType) {
    switch(itemType) {
        case Items::potions:
            return (itemCount == 1) ? "potion" : "potions";
        case Items::torches:
            return (itemCount == 1) ? "torch" : "torches";
        case Items::arrows:
            return (itemCount == 1) ? "arrow" : "arrows";
        default:
            return "Invalid";
    }
}

template <typename T>
constexpr std::size_t toUZ(T value) {
    static_assert(std::is_integral<T>() || std::is_enum<T>());
    return static_cast<std::size_t>(value);
}

int main()
{
    std::vector items {1, 5, 10};
    assert(items.size() == Items::maxItems);
    for(int i {0}; i < Items::maxItems; ++i) {
        std::cout << "You have " << items[toUZ(i)] << " " << getItemName(items[toUZ(i)], i) << '\n';
    }
    std::cout << "You have " << countTotalItems(items) << " total items\n";
    return 0;
}
