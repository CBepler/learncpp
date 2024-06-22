#include <iostream>

int main()
{
    int count{5};
    while(count > 0){
        int inner{count};
        while(inner > 0){
            std::cout << inner << ' ';
            --inner;
        }
        std::cout << '\n';
        --count;
    }
    return 0;
}
