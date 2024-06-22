#include <iostream>

int calculate(int x, int y, char32_t op){
    switch(op){
    case '+':
        return x + y;
    case '-':
        return x - y;
    case '*':
        return x * y;
    case '/':
        return x / y;
    case '%':
        return x % y;
    default:
        std::cout << "Invalid operator\n";
        return NULL;
    }
}

int main()
{
    std::cout << calculate(10, 2, '+') << '\n';
    std::cout << calculate(10, 2, '-') << '\n';
    std::cout << calculate(10, 2, '*') << '\n';
    std::cout << calculate(10, 2, '/') << '\n';
    std::cout << calculate(10, 2, '%') << '\n';
    std::cout << calculate(10, 2, 'k') << '\n';
    return 0;
}
