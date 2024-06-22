#include <iostream>

int main()
{
    int count{97};
    while(count <= 122){
        std::cout << static_cast<char>(count) << ' ' << count <<  '\n';
        ++count;
    }
    return 0;
}
