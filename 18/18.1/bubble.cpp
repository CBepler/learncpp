#include <iostream>
#include <iterator>
#include <utility>

int main()
{
    int array[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };
    constexpr int length {static_cast<int>(std::size(array))};
    for(int i {length - 1}; i >= 0; --i) {
        bool swapped {false};
        for(int j {1}; j <= i; ++j) {
            if (array[j - 1] > array[j]) {
                std::swap(array[j - 1], array[j]);
                swapped = true;
            }
        }
        if(!swapped) {
            std::cout << "Early termination on iteration " << length - i << '\n';
            break;
        }
    }

    for (int index{ 0 }; index < length; ++index) {
        std::cout << array[index] << ' ';
    }

    
    return 0;
}
