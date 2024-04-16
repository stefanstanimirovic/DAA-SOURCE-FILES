#include <vector>
#include <climits>
using namespace std;

int knapsackNoRepeat(int n, int W, int w[], int c[]) {
    // formiranje matrice d dimenzija (W + 1) x (n + 1)
    vector<vector<int>> d(W + 1, vector<int>(n + 1));

    // popunjavamo pocetne vrednosti
    for (int i = 0; i <= W; i++) {
        d[i][0] = 0;
    }
    for (int j = 1; j <= n; j++) {
        d[0][j] = 0;
    }

    // primena rekurentne formule
    for (int i = 1; i <= W; i++) {
        for (int j = 1; j <= n; j++) {
            int v1 = d[i][j - 1];
            int v2 = (w[j - 1] <= i) 
                ? (c[j - 1] + d[i - w[j - 1]][j - 1]) 
                : INT_MIN;
            d[i][j] = (v1 > v2) ? v1 : v2;
        }
    }

    return d[W][n];
}