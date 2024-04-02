#include <algorithm>
using namespace std;

bool duplicate(int a[], int n, int& d) {
	sort(a, a + n);   // O(n log n)
	for (int i = n - 1; i > 0; i--) { // O(n)
		if (a[i] == a[i - 1]) {
			d = a[i];
			return true;
		}
	}
	return false;
}