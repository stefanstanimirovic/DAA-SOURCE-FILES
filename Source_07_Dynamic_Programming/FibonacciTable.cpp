#include <vector>
using namespace std;

int FibonacciTable(int n) {
	vector<int> table(n + 1, 0);
	table[1] = 1;
	for (int i = 2; i <= n; i++) {
		table[i] = table[i - 1] + table[i - 2];
	}
	return table[n];
}