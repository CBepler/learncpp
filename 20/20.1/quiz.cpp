#include <iostream>
#include <limits>
#include <type_traits>
#include <functional>

using ArithmeticFunction = std::function<int(int, int)>;


template <typename T>
bool checkInput(T val) {
    if(std::is_same<T, char>::value) {
        switch(val) {
            case('+'):
            case('-'):
            case('*'):
            case('/'):
                return true;
            default:
                std::cout << "Please enter a valid operator (+, -, *, /): ";
                return false;
        }
    }
    return true;
}

template <typename T>
T getInput() {
    static_assert(std::is_same<T, int>::value || std::is_same<T, char>::value);
    if(std::is_same<T, int>::value) {
        std::cout << "Enter an integer: ";
    } else if(std::is_same<T, char>::value) {
        std::cout << "Enter an operator (+, -, *, /): ";
    }
    T val {};
    while(true) {
        std::cin >> val;
        if(!std::cin) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Please enter a valid value\n";
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if(!checkInput(val)) {
            continue;
        }
        return val;
    }
}

int add(int x, int y) {
    return x + y;
}

int subtract(int x, int y) {
    return x - y;
}

int multiply(int x, int y) {
    return x * y;
}

int divide(int x, int y) {
    return x / y;
}

ArithmeticFunction getArithmeticFunction(char op) {
    switch(op) {
        case('+'): return &add;
        case('-'): return &subtract;
        case('*'): return &multiply;
        case('/'): return &divide;
        default: return nullptr;
    }
}

int main()
{
    int num1 {getInput<int>()};
    char op {getInput<char>()};
    int num2 {getInput<int>()};
    ArithmeticFunction calculate {getArithmeticFunction(op)};
    if(calculate) {
        std::cout << num1 << " " << op << " " << num2 << " = " << calculate(num1, num2) << '\n';
    }
    return 0;
}
