int missing_number_1(int n, int a[]) {
	int result = -1;
	for (int x = 0; result == -1 && x <= n; x++) {
		int j;
		for (j = 0; j < n; j++) {
			if (a[j] == x) {
				break;
			}
		}
		if (j == n) {
			result = x;
		}
	}
	return result;
}