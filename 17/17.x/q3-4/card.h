#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <array>
#include <cstddef>

struct Card {
    enum Ranks {
        ace,
        two, 
        three,
        four,
        five,
        six,
        seven,
        eight,
        nine,
        ten,
        jack,
        queen,
        king,
        max_rank,
    };

    enum Suits {
        clubs,
        diamonds,
        hearts,
        spades,
        max_suit,
    };

    static constexpr std::array rankCodes {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
    static constexpr std::array suitCodes {'C', 'D', 'H', 'S'};
    static constexpr std::array allRanks {ace, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king};
    static constexpr std::array allSuits {clubs, diamonds, hearts, spades};
    static constexpr std::array rankValues { 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 };


    static_assert(rankCodes.size() == max_rank);
    static_assert(suitCodes.size() == max_suit);
    static_assert(allRanks.size() == max_rank);
    static_assert(allSuits.size() == max_suit);
    static_assert(rankValues.size() == max_rank);


    Ranks rank {};
    Suits suit {};

    friend std::ostream& operator<<(std::ostream& out, const Card &card)
    {
        out << Card::rankCodes[card.rank] << Card::suitCodes[card.suit];
        return out;
    }

    int value() const
    {
        return rankValues[rank];
    }

};

#endif