int farm_2(int n, int m, int k) {
	if (n > m) {
		int t = n; n = m; m = t;
	}
	if (n + k <= m) {
		n = n + k;
	}
	else {
		int rem = k - (m - n);
		n = m + rem / 2;
		m = m + (rem + 1) / 2;
	}
	return n * m;
}