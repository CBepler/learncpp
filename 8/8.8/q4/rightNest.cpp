#include <iostream>

int main()
{
    int count{1};
    while(count <= 5){
        int inner{5};
        while(inner > 0){
            if(inner > count){
                std::cout << "  ";
            }
            else{
                std::cout << inner << ' ';
            }
            --inner;
        }
        std::cout << '\n';
        ++count;
    }
    return 0;
}
