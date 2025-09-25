#ifndef POKER_H
#define POKER_H

#include "card.h"
#include <vector>

int evaluateHand(const std::vector<Card>& hand);  // returns a score
std::string handRankToString(int rank);           // readable rank

#endif
