#include <iostream>

int getInput(){
    std::cout << "Enter an integer: ";
    int num; //num created
    std::cin >> num;
    return num;
} //num destroyed

int main()
{
    int smaller{getInput()}; //smaller created
    int larger{getInput()}; //larger created
    if(smaller > larger){
        std::cout << "swapping\n";
        int tempSmall{smaller}; //tempSmall created
        smaller = larger;
        larger = tempSmall;
    } //tempSmall destroyed
    std::cout << "Smaller: " << smaller << "\nLarger: " << larger;
    return 0;
} //smaller, larger destroyed
