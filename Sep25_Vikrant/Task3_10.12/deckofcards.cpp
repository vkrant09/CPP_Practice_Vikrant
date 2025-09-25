#include "deckofcards.h"
#include <algorithm>
#include <ctime>
#include <cstdlib>

DeckOfCards::DeckOfCards() : currentCard(0) {
    for (int suit = 0; suit < 4; ++suit) {
        for (int face = 0; face < 13; ++face) {
            deck.push_back(Card(face, suit));
        }
    }
    std::srand(static_cast<unsigned>(std::time(0)));
}

void DeckOfCards::shuffle() {
    std::random_shuffle(deck.begin(), deck.end());
    currentCard = 0;
}

Card DeckOfCards::dealCard() {
    if (moreCards()) {
        return deck[currentCard++];
    }
    return Card(0,0); // dummy fallback
}

bool DeckOfCards::moreCards() const {
    return currentCard < deck.size();
}
