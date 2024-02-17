long long exp_s1_ineffective(int n) {
	long result = 0;
	for (int i = 1; i <= n; i++) {
		int member = 1;
		for (int k = i; k <= 2 * i; k++) {
			member = member * k;
		}
		result = result + member;
	}
	return result;
}