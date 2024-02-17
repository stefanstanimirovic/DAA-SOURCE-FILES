double exp_s2(int n) {
	double num = 0, denum = 1, sign = 1, result = 0;
	for (int i = 1; i <= n; i++) {
		num = num + i;
		denum = denum * i;
		result = result + sign * num / denum;
		sign = -sign;
	}
	return result;
}

double exp_s3(int n) {
	double num = 2, denum = 1, result = 0;
	double fact = 1, exp = 2;
	for (int i = 1; i <= n; i++) {
		result = result + num / denum;
		exp = exp * 4;
		num = num * exp;
		fact = fact * (i + 1);
		denum = denum + fact;
	}
	return result;
}