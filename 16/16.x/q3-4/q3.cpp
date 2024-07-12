#include <iostream>
#include <vector>
#include <cassert>
#include <limits>

template <typename T>
std::size_t toUZ(T val) {
    static_assert(std::is_integral<T>() || std::is_enum<T>());

    return static_cast<std::size_t>(val);
}

template <typename T>
std::pair<int, int> makePair(const std::vector<T>& arr) {
    assert(arr.size() > 0);
    std::pair minMax {0, 0};
    int length {static_cast<int>(arr.size())};
    for(int i {1}; i < length; ++i) {
        if(arr[toUZ(i)] > arr[toUZ(minMax.second)]) {
            minMax.second = i;
        }
        if(arr[toUZ(i)] < arr[toUZ(minMax.first)]) {
            minMax.first = i;
        }
    }
    return minMax;
}

template <typename T>
void printArray(const std::vector<T>& arr) {
    std::cout << "With array {";
    bool comma {false};
    for(const auto& el : arr) {
        if(comma) {
            std::cout << ", ";
        }
        std::cout << el;
        comma = true;
    }
    std::cout << "}:\n";
}

template <typename T>
void printInfo(const std::vector<T>& arr) {
    printArray(arr);
    std::pair minMax {makePair(arr)};
    std::cout << "The min element has index " << minMax.first << " and value " << arr[toUZ(minMax.first)] << '\n';
    std::cout << "The max element has index " << minMax.second << " and value " << arr[toUZ(minMax.second)] << '\n';
}

std::vector<int> getUserVector() {
    std::cout << "Enter numbers to add (use -1 to stop): ";
    std::vector<int> arr {};
    while(true) {
        int x {};
        std::cin >> x;
        if(!std::cin) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\nPlease only enter integers\n";
            continue;
        }
        if(x == -1) {
            if(arr.size() != 0) {
                std::cout << '\n';
                return arr;
            }
            std::cout << "\nPlease enter at least one value\n";
        } else {
            arr.push_back(x);
        }
    }
}

int main()
{
    std::vector v {getUserVector()};
    printInfo(v);

    std::cout << '\n';

    std::vector v1 { 3, 8, 2, 5, 7, 8, 3 };
    printInfo(v1);

    std::cout << '\n';

    std::vector v2 { 5.5, 2.7, 3.3, 7.6, 1.2, 8.8, 6.6 };
    printInfo(v2);

    return 0;
}
