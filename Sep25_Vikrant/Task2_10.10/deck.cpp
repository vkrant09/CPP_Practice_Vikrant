#include "deck.h"
#include <algorithm>
#include <cstdlib>
#include <ctime>

DeckOfCards::DeckOfCards() : currentCard(0) {
    // build 52 cards
    for (int suit = 0; suit < 4; suit++) {
        for (int face = 0; face < 13; face++) {
            deck.push_back(Card(face, suit));
        }
    }
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

void DeckOfCards::shuffle() {
    for (size_t i = 0; i < deck.size(); i++) {
        int j = std::rand() % deck.size();
        std::swap(deck[i], deck[j]);
    }
    currentCard = 0;
}

Card DeckOfCards::dealCard() {
    if (moreCards()) {
        return deck[currentCard++];
    }
    return Card(); // return default card if no more
}

bool DeckOfCards::moreCards() const {
    return currentCard < static_cast<int>(deck.size());
}
