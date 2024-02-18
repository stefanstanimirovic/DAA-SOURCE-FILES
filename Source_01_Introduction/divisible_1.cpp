int divisible_1(int a, int b, int k) {
	int result = 0;
	for (int i = a; i <= b; i++) {
		if (i % k == 0) {
			result++;
		}
	}
	return result;
}