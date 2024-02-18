#include <climits>  // Zbog vrednosti INT_MIN
#include <vector>
using namespace std;

int max_sum_subarray_3(int n, int a[]) {
	// Prekalkulacija:   s[i] je suma prvih i elemenata niza a
	vector<int> s(n + 1);
	s[0] = 0;
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + a[i - 1];
	}

	// Resavanje: Po svim desnim granicama j nalazimo najmanje iz skupa {s[0], s[1], ... s[j]}
	int min = 0;
	int maxSum = INT_MIN;
	for (int j = 1; j <= n; j++) {
		if (s[j] - min > maxSum) {
			maxSum = s[j] - min;
		}
		if (s[j] < min) {
			min = s[j];
		}
	}
	return maxSum;
}