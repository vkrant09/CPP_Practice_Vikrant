#include "deck.h"
#include <iostream>

int main() {
    DeckOfCards deck;
    deck.shuffle();

    int count = 0;
    while (deck.moreCards()) {
        std::cout << deck.dealCard().toString() << "\n";
        count++;
    }

    std::cout << "\nTotal cards dealt: " << count << "\n";

    return 0;
}
