#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H

#include "card.h"
#include <vector>

class DeckOfCards {
private:
    std::vector<Card> deck;
    int currentCard;

public:
    DeckOfCards();

    void shuffle();
    Card dealCard();
    bool moreCards() const;
};

#endif
