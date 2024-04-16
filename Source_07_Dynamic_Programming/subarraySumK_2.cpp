#include <vector>
using namespace std;

bool isSubsetSum2(int a[], int n, int k) {
    vector<vector<bool>> dp(2, vector<bool>(k + 1));

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if (j == 0) {
                dp[i % 2][j] = true;
            }
            else if (i == 0) {
                dp[i % 2][j] = false;
            }
            else if (a[i - 1] > j) {
                dp[i % 2][j] = dp[(i + 1) % 2][j];
            }
            else {
                dp[i % 2][j] = dp[(i + 1) % 2][j - a[i - 1]]
                    || dp[(i + 1) % 2][j];
            }
        }
    }

    return dp[n % 2][k];
}