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
	int i = n - 1;
	while (i >= 0) {
		if (i != 0 && d[i + 1] == d[i - 1] + a[i]) {
			cout << a[i] << " ";
			i = i - 2;
		}
		else if (i != 0) {
			i = i - 1;
		}
		else {
			cout << a[i] << " ";
			i = i - 2;
		}
	}
	cout << endl;
	return d[n];
}