int divisible_2(int a, int b, int k) {
	int left = a / k + (a % k != 0);
	int right = b / k;
	return (right >= left) ? (right - left + 1) : 0;
}