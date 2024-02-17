long long exp_s1(int n) {
	int member = 1 * 2;
	long result = member;
	for (int i = 2; i <= n; i++) {
		member = member * (2 * i - 1) * (2 * i) / (i - 1);
		result = result + member;
	}
	return result;
}