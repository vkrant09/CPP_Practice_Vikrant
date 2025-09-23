#include "bucketsort.h"
#include <iostream>

int main() {
    int arr[] = {97, 3, 100, 25, 76, 53, 41, 12};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    bucketSort(arr, size);

    std::cout << "Sorted array:   ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
