int missing_number_3(int n, int a[]) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
	}
	return n * (n + 1) / 2 - sum;
}