#include "deckofcards.h"
#include "poker.h"
#include <iostream>
#include <vector>

int main() {
    DeckOfCards deck;
    deck.shuffle();

    std::vector<Card> hand1;
    std::vector<Card> hand2;

    // deal 5 cards each
    for (int i=0; i<5; ++i) {
        hand1.push_back(deck.dealCard());
        hand2.push_back(deck.dealCard());
    }

    std::cout << "Hand 1:\n";
    for (size_t i=0;i<hand1.size();++i)
        std::cout << "  " << hand1[i].toString() << "\n";
    int rank1 = evaluateHand(hand1);
    std::cout << "Rank: " << handRankToString(rank1) << "\n\n";

    std::cout << "Hand 2:\n";
    for (size_t i=0;i<hand2.size();++i)
        std::cout << "  " << hand2[i].toString() << "\n";
    int rank2 = evaluateHand(hand2);
    std::cout << "Rank: " << handRankToString(rank2) << "\n\n";

    // decide winner
    if (rank1 > rank2)
        std::cout << "Hand 1 wins!\n";
    else if (rank2 > rank1)
        std::cout << "Hand 2 wins!\n";
    else
        std::cout << "It's a tie!\n";

    return 0;
}
