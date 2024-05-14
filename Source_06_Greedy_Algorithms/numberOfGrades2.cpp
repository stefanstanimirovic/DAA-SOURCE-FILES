int numberOfGrades2(int a[], int n) {
	int ocene[6]; // koristimo elemente ocene[1], ..., ocene[5]
	for (int i = 0; i <= 5; i++) {
		ocene[i] = 0; // pocetne vrednosti za broj svake ocene
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i]; // zbir svih ocena
		ocene[a[i]]++; // prebrojavanje svake ocene
	}
	int result = 0; // broj ocena koje treba popraviti
	for (int k = 1; k <= 5; k++) {
		for (int i = 0; i < ocene[k]; i++) {
			if (sum >= 4.5 * n) {
				break;
			}
			sum += (5 - k); // popravlja ocenu k
			result++; // broj popravljenih ocena se povecava za jedan
		}
	}
	return result;
}