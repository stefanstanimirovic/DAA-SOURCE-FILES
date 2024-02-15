#include <vector>
using namespace std;

vector<bool> eratosten(int n) {
    vector<bool> sito(n + 1, true);
    for (int i = 2; i <= n; i++) {
        if (sito[i]) {
            for (int j = 2; i * j <= n; j++) {
                sito[i * j] = false;
            }
        }
    }
    return sito;
}