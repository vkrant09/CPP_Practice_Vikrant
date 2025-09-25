#include "card.h"

const std::string Card::faces[13] = {
    "Ace", "Deuce", "Three", "Four", "Five", "Six",
    "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"
};

const std::string Card::suits[4] = {
    "Hearts", "Diamonds", "Clubs", "Spades"
};

Card::Card(int cardFace, int cardSuit) : face(cardFace), suit(cardSuit) {}

std::string Card::toString() const {
    return faces[face] + " of " + suits[suit];
}
