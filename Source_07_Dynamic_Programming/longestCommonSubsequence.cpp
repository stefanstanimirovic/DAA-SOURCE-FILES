#include <vector>
#include <iostream>
using namespace std;

int longestCommonSubsequence(double a[], double b[], int n, int m) {
    vector<vector<int>> L(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                L[i][j] = 1 + L[i - 1][j - 1];
            }
            else {
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }
    }

    int index = L[n][m];
    vector<int> subsequence(index);

    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            subsequence[--index] = a[i - 1];
            i--;
            j--;
        }
        else if (L[i - 1][j] > L[i][j - 1]) {
            i--;
        }
        else {
            j--;
        }
    }

    // Stampanje niza
    for (int i = 0; i < index; i++) {
        cout << subsequence[i] << " ";
    }

    return L[n][m];
}