unsigned long long countAllDivisors2(unsigned long long n) {
	unsigned long long total = 1;
	for (unsigned long long i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			unsigned long long e = 0;
			do {
				e++;
				n /= i;
			} while (n % i == 0);
			total *= e + 1;
		}
	}
	if (n > 1) {
		total *= 2;
	}
	return total;
}