int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

int gcd_it(int a, int b) {
	while (b) {
		a %= b;
		int t = a; a = b; b = t;
	}
	return a;
}