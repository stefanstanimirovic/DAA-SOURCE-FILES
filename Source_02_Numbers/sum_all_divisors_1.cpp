unsigned long long sumAllDivisors1(unsigned long long n) {
	unsigned long long sum = 0;
	unsigned long long i = 1;
	for ( ; i * i <= n; i++) {
		if (n % i == 0) {
			sum += (i + n / i);
		}
	}
	if (i * i == n) {
		sum += i;
	}
	return sum;
}