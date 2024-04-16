#include <vector>
using namespace std;

int knapsackRepeat(int n, int c[], int w[], int W) {
    vector<int> d(W + 1);
    d[0] = 0;
    for (int i = 1; i <= W; i++) { // kapaciteti ranca
        int val = 0;
        for (int j = 0; j < n; j++) { // indeksi predmeta
            if (w[j] <= i && c[j] + d[i - w[j]] > val) {
                val = c[j] + d[i - w[j]];
            }
        }
        d[i] = val;
    }
    return d[W];
}