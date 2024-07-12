#include <iostream>
#include <vector>
#include <string_view>
#include <cassert>

void playGame(int num) {
    static const std::vector divisors {3, 5, 7, 11, 13, 17, 19};
    static const std::vector<std::string_view> words {"fizz", "buzz", "pop", "bang", "jazz", "pow", "boom"};
    assert(divisors.size() == words.size());

    for(int i {1}; i <= num; ++i) {
        bool div {false};
        for(std::size_t j {0}; j < divisors.size(); ++j) {
            if(i % divisors[j] == 0) {
                div = true;
                std::cout << words[j];
            }
        }
        if(!div) {
            std::cout << i;
        }
        std::cout << '\n';
    }
}

int main()
{
    playGame(150);
    return 0;
}
