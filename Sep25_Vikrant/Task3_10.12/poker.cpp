#include "poker.h"
#include <algorithm>

// rank levels: 1=HighCard, 2=Pair, 3=TwoPair, 4=ThreeKind, 5=Straight,
// 6=Flush, 7=FullHouse, 8=FourKind, 9=StraightFlush

static bool isFlush(const std::vector<Card>& hand) {
    int s = hand[0].getSuit();
    for (size_t i=1;i<hand.size();++i)
        if (hand[i].getSuit()!=s) return false;
    return true;
}

static bool isStraight(std::vector<int> faces) {
    std::sort(faces.begin(), faces.end());
    for (int i=1;i<5;++i)
        if (faces[i] != faces[i-1]+1) return false;
    return true;
}

int evaluateHand(const std::vector<Card>& hand) {
    std::vector<int> faces;
    for (size_t i=0;i<hand.size();++i) faces.push_back(hand[i].getFace());

    bool flush = isFlush(hand);
    bool straight = isStraight(faces);

    // count frequencies
    int counts[13] = {0};
    for (size_t i=0;i<faces.size();++i) counts[faces[i]]++;

    int pair=0, three=0, four=0;
    for (int i=0;i<13;++i) {
        if (counts[i]==2) pair++;
        else if (counts[i]==3) three++;
        else if (counts[i]==4) four++;
    }

    if (straight && flush) return 9;
    if (four==1) return 8;
    if (three==1 && pair==1) return 7;
    if (flush) return 6;
    if (straight) return 5;
    if (three==1) return 4;
    if (pair==2) return 3;
    if (pair==1) return 2;
    return 1; // high card
}

std::string handRankToString(int rank) {
    switch(rank) {
        case 9: return "Straight Flush";
        case 8: return "Four of a Kind";
        case 7: return "Full House";
        case 6: return "Flush";
        case 5: return "Straight";
        case 4: return "Three of a Kind";
        case 3: return "Two Pair";
        case 2: return "One Pair";
        default: return "High Card";
    }
}
