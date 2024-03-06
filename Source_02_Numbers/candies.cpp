#include <vector>
using namespace std;

// Import gcd function
int gcd(int, int);

int candies(int n, int a[]) {
	vector<int> L(n + 1);
	// L[i] = nzd(a[0], a[1], ..., a[i - 1])
	// L[i] = nzd prvih i elemenata niza a
	L[0] = 0;
	for (int i = 1; i <= n; i++) {
		L[i] = gcd(L[i - 1], a[i - 1]);
	}

	vector<int> R(n + 1);
	// R[i] = nzd(a[n - i], a[n - i + 1], ..., a[n - 1])
	// R[i] = nzd poslednjih i elemenata niza a
	R[0] = 0;
	for (int i = 1; i <= n; i++) {
		R[i] = gcd(a[n - i], R[i - 1]);
	}

	int max = 1;
	for (int i = 0; i < n; i++) {
		int d = gcd(L[i], R[n - 1 - i]);
		if (d > max) {
			max = d;
		}
	}
	return max;
}