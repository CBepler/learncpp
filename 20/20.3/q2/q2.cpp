#include <iostream>

int sumParts(int parts) {
    if(parts < 10) {
        return parts;
    }
    return (parts % 10) + sumParts(parts / 10);
}

int main()
{
    std::cout << sumParts(357);
    return 0;
}
