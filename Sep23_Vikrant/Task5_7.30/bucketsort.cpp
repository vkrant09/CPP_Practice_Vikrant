#include "bucketsort.h"
#include <iostream>
#include <vector>
#include <cmath>

void bucketSort(int arr[], int size) {
    if (size <= 0) {
        return;
    }

    // Find max element to know number of digits
    int maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    int maxDigits = 0;
    while (maxVal > 0) {
        maxDigits++;
        maxVal /= 10;
    }

    // Buckets: 10 rows, size columns
    std::vector<std::vector<int>> buckets(10, std::vector<int>(size));

    for (int digitPos = 0; digitPos < maxDigits; digitPos++) {
        // Track counts per bucket
        std::vector<int> counts(10, 0);

        // Distribution pass
        for (int i = 0; i < size; i++) {
            int digit = (arr[i] / static_cast<int>(std::pow(10, digitPos))) % 10;
            buckets[digit][counts[digit]++] = arr[i];
        }

        // Gathering pass
        int index = 0;
        for (int b = 0; b < 10; b++) {
            for (int j = 0; j < counts[b]; j++) {
                arr[index++] = buckets[b][j];
            }
        }
    }
}
