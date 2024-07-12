#include <iostream>
#include <vector>
#include <string_view>

template <typename T>
bool checkArr(const std::vector<T>& arr, const T& guess) {
    for(const T& name : arr) {
        if (name == guess) {
            return true;
        }
    }
    return false;
}

int main()
{
    using namespace std::string_view_literals;
    
    std::vector arr {"Alex"sv, "Betty"sv, "Caroline"sv, "Dave"sv, "Emily"sv, "Fred"sv, "Greg"sv, "Holly"sv};

    std::cout << "Enter a name: ";
    std::string input {};
    std::cin >> input;

    if(checkArr<std::string_view>(arr, input)) {
        std::cout << input << " was found.\n";
    } else {
        std::cout << input << " was not found.\n";
    }

    return 0;
}
