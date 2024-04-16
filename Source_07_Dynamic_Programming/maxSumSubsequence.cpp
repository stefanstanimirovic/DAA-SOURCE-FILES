#include <climits>

int maxSumSubsequence(int a[], int n) {
    int currentSum = 0;
    int maxSum = INT_MIN;

    for (int i = 0; i < n; i++) {
        currentSum = (a[i] > currentSum + a[i]) ? a[i] : currentSum + a[i];
        maxSum = (maxSum > currentSum) ? maxSum : currentSum;
    }

    return maxSum;
}