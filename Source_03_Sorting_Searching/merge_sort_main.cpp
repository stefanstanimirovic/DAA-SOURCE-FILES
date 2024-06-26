#pragma once
#include <vector>
#include <iostream>
using namespace std;

// Imports from other files
void printArray(int arr[], int arrSize);
void mergeSort(int arr[], int arrSize);

void printArray(int arr[], int arrSize) {
    for (int i = 0; i < arrSize; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int MergeSortMain() {
    int arr[] = { 12, 11, 13, 5, 6, 7, 15, 3, 8, 14, 4 };
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Given array is \n";
    printArray(arr, arrSize);

    mergeSort(arr, arrSize);

    std::cout << "\nSorted array is \n";
    printArray(arr, arrSize);

    return 0;
}