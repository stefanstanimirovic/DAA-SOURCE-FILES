#pragma once
#include <vector>
#include <iostream>
using namespace std;

// Imports from other files
vector<int> findKClosestElements(int a[], int m, int k, int n);

int main() {
    int a[] = {2, 3, 4, 5, 6, 7};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 2, m = 8;

    vector<int> nums = findKClosestElements(a, m, k, n);
    for (int x : nums) {
        cout << x << " ";
    }

    return 0;
}