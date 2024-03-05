unsigned long long sumAllDivisors2(unsigned long long n) {
	unsigned long long total = 1;
	for (unsigned long long i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			unsigned long long e = 0;
			do {
				e++;
				n /= i;
			} while (n % i == 0);
			unsigned long long sum = 0, pow = 1;
			do {
				sum += pow;
				pow *= i;
			} while (e-- > 0);
			total *= sum;
		}
	}
	if (n > 1) {
		total *= (1 + n);
	}
	return total;
}