#include <vector>
using namespace std;

bool isSubsetSum3(int a[], int n, int k) {
    vector<bool> dp(k + 1);
    dp[0] = true; // moguce je kreirati podniz za zbirom 0

    for (int i = 0; i < n; i++) {
        for (int j = k; j >= a[i]; j--) {
            if (dp[j - a[i]] == true) {
                dp[j] = true;
            }
        }
    }

    return dp[k];
}