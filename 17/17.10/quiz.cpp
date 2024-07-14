#include <iostream>

void printString(const char arr[]) {
    while(*arr != '\0') {
        std::cout << *arr;
        ++arr; 
    }
    std::cout << '\n';
}

void printStringReverse(const char* arr) {
    if(*arr != '\0') {
        printStringReverse(arr + 1);
    }
    std::cout << *arr;
}

int main()
{
    const char hello[] {"Hello, World!"};
    printString(hello);
    printStringReverse(hello);
    return 0;
}
