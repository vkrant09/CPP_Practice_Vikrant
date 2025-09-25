#include "card.h"

const std::string Card::faces[13] =
    {"Ace","Two","Three","Four","Five","Six","Seven",
     "Eight","Nine","Ten","Jack","Queen","King"};

const std::string Card::suits[4] =
    {"Hearts","Diamonds","Clubs","Spades"};

Card::Card(int faceVal, int suitVal) : face(faceVal), suit(suitVal) {}

std::string Card::toString() const {
    return faces[face] + " of " + suits[suit];
}

int Card::getFace() const { return face; }
int Card::getSuit() const { return suit; }
