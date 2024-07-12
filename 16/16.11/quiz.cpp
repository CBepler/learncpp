#include <iostream>
#include <vector>

template <typename T>
void printVector(const std::vector<T>& arr) {
    if(arr.size() == 0){
        std::cout << "(Stack: empty)\n";
        return;
    }
    std::cout << "(Stack: ";
    for(const auto& el : arr) {
        std::cout << el << " ";
    }
    std::cout << ")\n";
}

int main()
{
    std::vector<int> arr {};
    printVector(arr);
    arr.push_back(1);
    printVector(arr);
    arr.push_back(2);
    printVector(arr);
    arr.push_back(3);
    printVector(arr);
    arr.pop_back();
    printVector(arr);
    arr.push_back(4);
    printVector(arr);
    arr.pop_back();
    printVector(arr);
    arr.pop_back();
    printVector(arr);
    arr.pop_back();
    printVector(arr);
    return 0;
}
