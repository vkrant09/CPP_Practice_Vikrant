#include <iostream>
#include "quickSort.h"

int main() {
    int arr[] = {37, 2, 6, 4, 89, 8, 10, 12, 68, 45};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    for(int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    quickSort(arr, 0, n - 1);

    std::cout << "Sorted array:   ";
    for(int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    return 0;
}
