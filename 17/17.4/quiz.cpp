#include <iostream>
#include <array>
#include <string_view>

struct Item
{
    std::string_view name {};
    int gold {};
};

template<std::size_t N>
void printItemsArr(const std::array<Item, N>& arr) {
    for(const auto& e : arr) {
        std::cout << "A " << e.name << " costs " << e.gold << " gold.\n";
    }
}


int main()
{
    constexpr std::array<Item, 4> items {{
        {"sword", 5},
        {"dagger", 3},
        {"club", 2},
        {"spear", 7},
    }};
    printItemsArr(items);
    return 0;
}
