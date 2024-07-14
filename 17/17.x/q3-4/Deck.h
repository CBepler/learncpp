#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <array>

class Deck {
private:
    static constexpr int s_deckSize {52};
    int m_currentCard {0};
    std::array<Card, 52> m_deck {};
public:
    Deck();
    Card dealCard();
    void shuffle();
};

#endif