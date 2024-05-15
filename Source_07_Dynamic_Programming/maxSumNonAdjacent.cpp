#include <vector>
#include <iostream>
using namespace std;

int maxSumNonAdjacent(int n, int a[]) {
	vector<int> d(n + 1);
	d[0] = 0;
	d[1] = (a[0] > 0) ? a[0] : 0;
	for (int i = 2; i <= n; i++) {
		int v1 = d[i - 2] + a[i - 1];
		int v2 = d[i - 1];
		d[i] = (v1 > v2) ? v1 : v2;
	}

	//Ispis elemenata koji su usli u sumu:
	int i = n;
	while (i > 0) {
		if (d[i] != d[i - 1]) {
			cout << a[i - 1] << " ";
			i = i - 2;
		}
		else {
			i = i - 1;
		}
	}
	cout << endl;
	return d[n];
}