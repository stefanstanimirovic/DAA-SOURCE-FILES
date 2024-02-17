#pragma once
#include <vector>
#include <utility>
using namespace std;

// Ulaz: Dva vektora iste dužine: 
// prices[i] predstavlja cenu goriva u i-tom gradu
// distances[i] predstavlja cenu puta od grada i do grada (i + 1) % n
// Izlaz: Vektor parova, gde prva koordinata predstavlja indeks grada
// gde je najpovoljnije sipati gorivo, a druga koordinata smer kretanja do tog grada
vector<pair<int, char>> barber_shop(const vector<double>& prices, const vector<double>& distances) {
	int n = prices.size(); // broj gradova
	vector<int> indices(n, -1); // niz indeksa gradova
	vector<char> directions(n, '0'); // niz smerova
	vector<double> newPrices(n, -1); // najjeftinije cene sipanja goriva

	// Nađi minimalnu cenu goriva, i indeks grada gde je ta cena
	int minIndex = 0, minValue = prices[0];
	for (int i = 1; i < n; i++) {
		if (prices[i] < minValue) {
			minValue = prices[i];
			minIndex = i;
		}
	}

	// Podesi da meštani ovog grada sipaju gorivo u tom gradu
	indices[minIndex] = minIndex;
	directions[minIndex] = '0';
	newPrices[minIndex] = prices[minIndex];
	
	// Posmatramo smer suprotan od kretanja kazaljke na satu
	// Za svaki grad koji prethodni minIndex gradu u ovom smeru
	// (indeksi se povećavaju)
	for (int i = (minIndex + 1) % n; i != minIndex; i = ((i + 1) % n)) {
		// Ako se više isplati da odemo do susednog mesta nego da ostanemo u i-tom gradu 
		if (distances[(i + n - 1) % n] + newPrices[(i + n - 1) % n] < prices[i]) {
			// Inače, plaćamo put do susednog grada i postupamo kao i ti meštani
			newPrices[i] = distances[(i + n - 1) % n] + newPrices[(i + n - 1) % n];
			indices[i] = indices[(i + n - 1) % n];
			directions[i] = '-';
		}
		else {
			// Ostajemo u i-tom gradu
			newPrices[i] = prices[i];
			indices[i] = i;
			directions[i] = '0';
		}
	}

	// Posmatramo smer kretanja kazaljke na satu
	// Za svaki grad koji prethodni minIndex gradu u ovom smeru
	// (indeksi se smanjuju)
	for (int i = (minIndex + n - 1) % n; i != minIndex; i = ((i + n - 1) % n)) {
		// Ako se više isplati da odemo do susednog mesta nego da ostanemo u i-tom gradu
		if (distances[i] + newPrices[(i + 1) % n] < newPrices[i]) {
			// Plaćamo put do susednog grada i postupamo kao i ti meštanu
			newPrices[i] = distances[i] + newPrices[(i + 1) % n];
			indices[i] = indices[(i + 1) % n];
			directions[i] = '+';
		}
	}

	// Formiramo izlaz
	vector<pair<int, char>> result;
	for (int i = 0; i < n; i++) {
		result.push_back(pair<int, char> {indices[i], directions[i]});
	}
	return result;
}