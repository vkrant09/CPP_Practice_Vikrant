#include <iostream>
#include "quickSort.h"

// QuickSort function: sorts arr[low..high] recursively
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array and get pivot index
        int pivotIndex = partition(arr, low, high);

        // Recursively sort elements before and after pivot
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

// Partition function: places pivot element in its correct position
int partition(int arr[], int low, int high) {
    int pivot = arr[low];       // Choose first element as pivot
    int left = low + 1;         // Start left pointer after pivot
    int right = high;           // Start right pointer at end of array

    while (true) {
        while (left <= right && arr[left] <= pivot)
            left++;
        while (left <= right && arr[right] >= pivot)
            right--;

        if (left > right)
            break;

        std::swap(arr[left], arr[right]); // Swap out-of-place elements
    }

    std::swap(arr[low], arr[right]); // Place pivot in final position
    return right;                     // Return pivot index
}
