#include <vector>
using namespace std;

int longestCommonSubsequenceLength(int a[], int n) {
    vector<int> d(n);
    d[0] = 1;
    int max = d[0];

    for (int i = 1; i < n; i++) {
        d[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j] && d[i] < d[j] + 1) {
                d[i] = d[j] + 1;
            }
        }
        max = (d[i] > max) ? d[i] : max;
    }

    return max;
}