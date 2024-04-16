#include <vector>
#include <iostream>
using namespace std;

void sumSubsets(int set[], int size, int n, int k) {
	// Kreiramo dinamicki niz duzine size koji 
	// predstavlja binarni zapis broja n 
	vector<int> x(size);
	int j = size - 1;

	// Konverzija broja n u binarni niz
	while (n > 0) {
		x[j] = n % 2;
		n = n / 2;
		j--;
	}

	int sum = 0;
	// Racunamo sumu elemenata podniza cija je
	// funkcija podskupa zadata maskom x
	for (int i = 0; i < size; i++) {
		if (x[i] == 1) {
			sum = sum + set[i];
		}
	}

	// Ukoliko je suma jednaka k, stampamo podniz
	if (sum == k) {
		for (int i = 0; i < size; ++i) {
			if (x[i] == 1) {
				cout << set[i] << " ";
			}
		}
		cout << endl;
	}
}

// Funkcija koja nalazi sve podnizove sa sumom k
void findSubsets(int arr[], int n, int k) {
	// Ukupan broj podskupova
	int x = pow(2, n);

	// Petlja po broju svih podskupova
	// Za svaki podskup se pozove prethodna funkcija
	for (int i = 1; i < x; i++) {
		sumSubsets(arr, n, i, k);
	}
}