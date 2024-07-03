#include <iostream>
#include <cmath>

struct adData {
    int adsWatched {};
    double percentUsersClicked {};
    double avgEarningsPerClick {};
};

adData getAdData() {
    adData temp {};
    std::cout << "How many ads were shown today? ";
    std::cin >> temp.adsWatched;
    std::cout << "What percentage of ads were clicked on by users? ";
    std::cin >> temp.percentUsersClicked;
    std::cout << "What was the average earnings per click? ";
    std::cin >> temp.avgEarningsPerClick;

    return temp;
}

void printAdData(const adData& data) {
    std::cout << "Ads watched: " << data.adsWatched << "\n";
    std::cout << "Percentage of users that clicked on the add: " << data.percentUsersClicked << "%\n";
    std::cout << "Average earnings per clicked ad: $" << data.avgEarningsPerClick << "\n";
    std::cout << "Total revenue: $" << round(data.adsWatched * data.avgEarningsPerClick * data.percentUsersClicked) / 100.0 << "\n";
}

int main()
{
    printAdData(getAdData());
    return 0;
}
