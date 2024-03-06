int gcd_unoptimal(int a, int b) {
	int limit = (a < b) ? a : b;
	for (int i = limit; i >= 1; i--) {
		if (a % i == 0 && b % i == 0) {
			return i;
		}
	}
	return 1;
}