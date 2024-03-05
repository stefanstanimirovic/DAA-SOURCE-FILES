#include <vector>
using namespace std;

vector<int> leastPrimeFactor(int n) {
    vector<int> sieve(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        if (sieve[i] == 0) {
            for (int j = 1; i * j <= n; j++) {
                if (sieve[i * j] == 0) {
                    sieve[i * j] = i;
                }
            }
        }
    }
    return sieve;
}