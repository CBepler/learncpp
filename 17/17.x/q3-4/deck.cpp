#include "Deck.h"
#include "card.h"
#include "Random.h"
#include <cassert>
#include <algorithm>

Deck::Deck() 
{
    int index {0};
    for (auto suit : Card::allSuits) {
        for (auto rank : Card::allRanks) {
            m_deck[index] =  Card { rank, suit };
            ++index;
        }
    }
}

Card Deck::dealCard() {
    assert((m_currentCard < s_deckSize) || "Deck is empty");
    ++m_currentCard;
    return m_deck[m_currentCard - 1];
}

void Deck::shuffle() {
    std::shuffle(m_deck.begin(), m_deck.end(), Random::mt);
    m_currentCard = 0;
}