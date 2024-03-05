unsigned long long countAllDivisors1(unsigned long long n) {
	unsigned long long count = 0;
	unsigned long long i = 1;
	for (; i * i <= n; i++) {
		if (n % i == 0) {
			count += 2;
		}
	}
	count += (i * i == n);
	return count;
}