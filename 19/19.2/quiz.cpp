#include <iostream>
#include <string>
#include <limits>
#include <algorithm>
#include <cstddef>

int getArrSize() {
    std::cout << "How many names do you wish to enter? ";
    std::size_t size {};
    while(true) {
        std::cin >> size;
        if(!std::cin || size < 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Please enter a valid size value\n";
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return size;
    }
}

int main()
{
    int length {getArrSize()};
    std::string* names {new std::string[static_cast<std::size_t>(length)]};

    for(int i {0}; i < length; ++i) {
        std::cout << "Enter name #" << i + 1 << ": ";
        std::getline(std::cin >> std::ws, names[i]);
    }

    std::sort(names, names + length);

    std::cout << "\nHere is your sorted list:\n";
    for(int i {0}; i < length; ++i) {
        std::cout << "Name #" << i + 1 << ": " << names[i] << '\n';
    }

    delete[] names;
    names = nullptr;

    return 0;
}
