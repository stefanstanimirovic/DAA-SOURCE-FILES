#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int numberOfJumpsDynamic(int a[], int n) {
    vector<int> d(n);
    if (n == 0 || a[0] == 0) {
        return INT_MAX;
    }

    d[0] = 0;
    for (int i = 1; i < n; i++) {
        d[i] = INT_MAX;
        for (int j = 0; j < i; j++) {
            if (i <= j + a[j] && d[j] != INT_MAX) {
                d[i] = min(d[i], d[j] + 1);
            }
        }
    }

    return d[n - 1];
}