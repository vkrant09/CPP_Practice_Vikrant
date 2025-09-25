#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H

#include "card.h"
#include <vector>

class DeckOfCards {
public:
    DeckOfCards();                     // make deck of 52 cards
    void shuffle();                    // shuffle the deck
    Card dealCard();                   // deal one card
    bool moreCards() const;            // are there more cards?

private:
    std::vector<Card> deck;
    int currentCard;
};

#endif
