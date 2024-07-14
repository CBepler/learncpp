#include "Deck.h"
#include <limits>
#include <iostream>

namespace Settings {
    int maxScore {21};
    int maxDealer {17};
}

struct Player {
    int score {0};
    int numAces {0};
};

enum class Outcome {
    win,
    lose,
    tie,
};

void checkAce(Card& card, Player& player) {
    if(card.rank == Card::ace) {
        player.numAces += 1;
    }
}

void convertAce(Player& player) {
    player.score -= 10;
    player.numAces -= 1;
    std::cout << "Ace converted from 11 to 1. New score: " << player.score << '\n';
}

bool dealerTurn(Deck& deck, Player& dealer) {
    while(dealer.score < Settings::maxDealer) {
        Card deal {deck.dealCard()};
        dealer.score += deal.value();
        std::cout << "The dealer flips a " << deal << ".  They now have: " << dealer.score << '\n';
        if(dealer.score > Settings::maxScore) {
            if(dealer.numAces > 0) {
                convertAce(dealer);
                continue;
            }
            std::cout << "The dealer went bust!\n";
            return true;
        }
    }

    return false;
}

bool playTurn(Deck& deck, Player& player) {
    while(true) {
        std::cout << "(h) to hit, or (s) to stand: ";
        char input {};
        std::cin >> input;
        if(!std::cin || (input != 'h' && input != 's')) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        if(input == 's') {
            return false;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        Card deal {deck.dealCard()};
        player.score += deal.value();
        std::cout << "You were dealt " << deal << ".  You now have: " << player.score << '\n';
        if(player.score > Settings::maxScore) {
            if(player.numAces > 0) {
                convertAce(player);
                continue;
            }
            std::cout << "You went bust!\n";
            return true;
        }
    }
}

Outcome playRound() {
    Deck deck{};
    deck.shuffle();

    Player player {0, 0};
    Player dealer {0, 0};

    Card dealerCard = deck.dealCard();
    checkAce(dealerCard, dealer);
    dealer.score += dealerCard.value();

    Card first = deck.dealCard();
    checkAce(first, player);
    player.score += first.value();

    Card second = deck.dealCard();
    checkAce(second, player);
    player.score += second.value();
    

    std::cout << "The dealer is showing: " << dealerCard << " (" <<  dealer.score << ")\n";
    std::cout << "You are showing: " << first << ' ' << second << " (" << player.score << ")\n";

    if(playTurn(deck, player)) {
        return Outcome::lose;
    }

    if(dealer.score < player.score) {
        if(dealerTurn(deck, dealer)) {
            return Outcome::win;
        }
    }

    if(player.score == dealer.score) {
        return Outcome::tie;
    }

    return player.score > dealer.score ? Outcome::win : Outcome::lose;
}


int main()
{
    //Deck deck{};
    // std::cout << deck.dealCard() << ' ' << deck.dealCard() << ' ' << deck.dealCard() << '\n';

    //deck.shuffle();
    // std::cout << deck.dealCard() << ' ' << deck.dealCard() << ' ' << deck.dealCard() << '\n';

    Outcome outcome {playRound()};

    if(outcome == Outcome::win) {
        std::cout << "You win\n";
    } else if(outcome == Outcome::lose) {
        std::cout << "You lose\n";
    } else if (outcome == Outcome::tie) {
        std::cout << "It's a tie\n";
    }

    return 0;
}