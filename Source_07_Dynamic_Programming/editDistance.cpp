#include <vector>
#include <iostream>
using namespace std;

int min(int x, int y, int z) {
    return min(min(x, y), z);
}

int editDistDP(string str1, string str2, int n, int m) {
    vector<vector<int>> d(n + 1, vector<int>(m + 1));

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0) {
                d[i][j] = j;
            }
            else if (j == 0) {
                d[i][j] = i;
            }
            else if (str1[i - 1] == str2[j - 1]) {
                d[i][j] = d[i - 1][j - 1];
            }
            else
                d[i][j] = 1 + min(
                    d[i][j - 1], // Insert
                    d[i - 1][j], // Remove
                    d[i - 1][j - 1] // Replace
                );
        }
    }

    return d[n][m];
}