#include <algorithm>
using namespace std;

int numberOfGrades1(int a[], int n) {
	// Sortiranje niza i nalazenje zbira ocena
	sort(a, a + n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
	}

	int result = 0; // broj ocena koje treba popraviti
	int i = 0; // indeks ocene koja se popravlja
	while (sum < 4.5 * n) {
		sum += (5 - a[i]); // ocena i se popravlja na 5
		i++; // indeks se pomera na sledecu ocenu
		result++; // broj popravljenih ocena se povecava za jedan
	}
	return result;
}