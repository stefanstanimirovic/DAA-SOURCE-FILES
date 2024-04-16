#include <vector>
using namespace std;

vector<int> longestCommonSubsequenceLength(int a[], int n) {
    vector<int> d(n);
    vector<int> p(n);

    d[0] = 1;
    p[0] = -1;

    int max = d[0];
    int maxIndex = 0;

    for (int i = 1; i < n; i++) {
        d[i] = 1;
        p[i] = -1;
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j] && d[i] < d[j] + 1) {
                d[i] = d[j] + 1;
                p[i] = j;
            }
        }
        if (d[i] > max) {
            max = d[i];
            maxIndex = i;
        }
    }

    vector<int> numbers;
    while (maxIndex != -1) {
        numbers.push_back(a[maxIndex]);
        maxIndex = p[maxIndex];
    }
    return numbers;
}