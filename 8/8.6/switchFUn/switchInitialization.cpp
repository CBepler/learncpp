#include <iostream>

int main()
{
    int x{2};
    switch (x)
    {
    case 0:
        int y;
        break;
    case 1:
        int c;
        y = 2;
        break;
    case 2:
        y = 1;
        std::cout << y;
        break;
    default:
        break;
    }
    return 0;
}
