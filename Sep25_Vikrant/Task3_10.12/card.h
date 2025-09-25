#ifndef CARD_H
#define CARD_H

#include <string>

// Class that represents a playing card
class Card {
public:
    Card(int faceVal, int suitVal);        // constructor
    std::string toString() const;          // return "Face of Suit"

    int getFace() const;                   // face value (0-12)
    int getSuit() const;                   // suit value (0-3)

    // arrays for faces and suits
    static const std::string faces[13];
    static const std::string suits[4];

private:
    int face;
    int suit;
};

#endif
