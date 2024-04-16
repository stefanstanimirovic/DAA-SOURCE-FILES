#include <iostream>
#include <vector>
#include <climits> 
using namespace std;

int minCostPath(int c[][1000], int n, int m) {
    vector<vector<int>> d(n, vector<int>(m, INT_MAX));

    // Postavi pocetnu vrednost u gornje levo polje
    d[0][0] = c[0][0];

    // Postavi svako polje u matrici
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            // Prodji kroz sve moguce mimimalne putanje i 
            if (i > 0) { // Gornje polje
                d[i][j] = min(d[i][j], d[i - 1][j] + c[i][j]);
            }
            if (j > 0) { // Levo polje
                d[i][j] = min(d[i][j], d[i][j - 1] + c[i][j]);
            }
            if (i > 0 && j > 0) {// Dijagonalno polje
                d[i][j] = min(d[i][j], d[i - 1][j - 1] + c[i][j]);
            }
        }
    }

    return d[n - 1][m - 1];
}