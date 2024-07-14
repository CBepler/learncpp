#include <iostream>
#include <array>

int main()
{
    constexpr std::array arr {'h', 'e', 'l', 'l', 'o'};
    std::cout << std::size(arr) << '\n';
    std::cout << arr[1] << arr.at(1) << std::get<1>(arr) << '\n';
    return 0;
}
