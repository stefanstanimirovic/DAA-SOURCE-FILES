#include <climits>  // Zbog vrednosti INT_MIN

int max_sum_subaray_2(int n, int a[]) {
	int maxSum = INT_MIN;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = i; j < n; j++) {
			sum += a[j];
			if (sum > maxSum) {
				maxSum = sum;
			}
		}
	}
	return maxSum;
}