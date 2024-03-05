#include <vector>
using namespace std;

void canon_factorization(int n, vector<int> &primes, vector<int> &exponents) {
	primes.resize(0); // Vektor za cuvanje prostih brojeva
	exponents.resize(0); // Vektor za cuvanje eksponenata
	for (int i = 2; i * i <= n; i++) {
		int count = 0;
		while (n % i == 0) {
			n /= i;
			count++;
		}
		if (count > 0) {
			primes.push_back(i);
			exponents.push_back(count);
		}
	}
	if (n > 1) {
		primes.push_back(n);
		exponents.push_back(1);
	}
}