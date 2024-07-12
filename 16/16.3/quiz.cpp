#include <vector>
#include <iostream>

int main()
{
    std::vector hello {'h', 'e', 'l', 'l', 'o'};
    std::cout << std::size(hello) << '\n';
    std::cout << hello.at(1) << '\n';
    std::cout << hello[1] << '\n';
    return 0;
}
