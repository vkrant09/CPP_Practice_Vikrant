#ifndef NUMBERSET_H
#define NUMBERSET_H

#include <vector>

class NumberSet {
private:
    std::vector<int> numbers; // stores unique numbers

public:
    NumberSet();

    void addNumber(int value);
    void displayUnique() const;
};

#endif
