#include <vector>
using namespace std;

bool isSubsetSum(int a[], int n, int k) {
    vector<vector<bool>> d(n + 1, vector<bool>(k + 1));

    // Ako je zbir 0, odgovor je true
    for (int i = 0; i <= n; i++) {
        d[i][0] = true;
    }

    // Ako suma nije 0 i podniz je prazan, odgovor je false
    for (int i = 1; i <= k; i++) {
        d[0][i] = false;
    }

    // Popunjavamo ostatak matrice d
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (j < a[i - 1]) {
                d[i][j] = d[i - 1][j];
            }
            else {
                d[i][j] = d[i - 1][j] || d[i - 1][j - a[i - 1]];
            }
        }
    }

    return d[n][k];
}