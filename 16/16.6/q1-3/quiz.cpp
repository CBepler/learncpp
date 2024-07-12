#include <iostream>
#include <vector>
#include <limits>

int getVal() {
    int val {};
    do {
        std::cout << "Enter a value between 1 and 9: ";
        std::cin >> val;

        if(!std::cin) {
            std::cin.clear();
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    } while (val < 1 || val > 9);

    return val;
}


template <typename T>
void printArray(const std::vector<T>& arr) {
    std::size_t length {arr.size()};
    for(std::size_t i {0}; i < length; ++i) {
        std::cout << arr[i] << ' ';
    }
    if(length > 0) {
        std::cout << '\n';
    }
}

template <typename T>
void findValue(T val, const std::vector<T>& arr) {
    for(std::size_t i {0}; i < arr.size(); ++i) {
        if (val == arr[i]) {
            std::cout << "The number " << val << " has index " << i << '\n';
            return;
        }
    }
    std::cout << "The number " << val << " was not found\n";
}

int main()
{
    std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };

    int val {getVal()};

    printArray(arr); // use function template to print array

    findValue(val, arr);

    return 0;
}