#include <iostream>
#include <cmath>

u_int64_t decimalToBinary(int num){
    u_int64_t binaryNum = 0;
    int highestPower = 0;
    while(pow(2, highestPower) < num){highestPower++;}
    for(int i = highestPower; i >= 0; i--){
        if(num >= pow(2, i)){
            binaryNum += pow(10, i);
            num -= pow(2, i);
        }
    }
    return binaryNum;
}

int main()
{
    std::cout << "Enter Number: ";
    int num;
    std::cin >> num;
    std::cout << decimalToBinary(num);
    return 0;
}
