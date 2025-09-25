#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
private:
    int face; // 0–12
    int suit; // 0–3

    static const std::string faces[13];
    static const std::string suits[4];

public:
    Card(int cardFace = 0, int cardSuit = 0);
    std::string toString() const;
};

#endif
