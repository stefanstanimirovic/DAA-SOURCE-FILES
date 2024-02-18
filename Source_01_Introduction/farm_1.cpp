int farm_1(int n, int m, int k) {
	int max = n * (m + k);
	for (int i = 1; i <= k; i++) {
		max = (n + i) * (m + k - i) > max ? (n + i) * (m + k - i) : max;
	}
	return max;
}