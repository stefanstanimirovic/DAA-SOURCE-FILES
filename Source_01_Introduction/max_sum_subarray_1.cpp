#include <climits>  // Zbog vrednosti INT_MIN

int max_sum_subaray_1(int n, int a[]) {
	// Proci kroz sve uzastopne podnizove i odrediti im sume
	// a[i], a[i + 1], ...., a[j];    i = 0, 1, ...., n - 1;    j = i, i + 1, ..., n - 1.
	int maxSum = INT_MIN;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int sum = 0;
			for (int k = i; k <= j; k++) {
				sum += a[k];
			}
			if (sum > maxSum) {
				maxSum = sum;
			}
		}
	}
	return maxSum;
}