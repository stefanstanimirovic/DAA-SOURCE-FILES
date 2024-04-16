#include <vector>
#include <climits>
using namespace std;

int numberOfCoins(int a[], int n, int x) {
    vector<int> d(x + 1);

    d[0] = 0;

    for (int i = 1; i <= x; i++) {
        d[i] = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (a[j] <= i) {
                int sub_res = d[i - a[j]];
                if (sub_res != INT_MAX && sub_res + 1 < d[i]) {
                    d[i] = sub_res + 1;
                }
            }
        }
    }

    if (d[x] == INT_MAX) {
        return -1;
    }

    return d[x];
}