#include <vector>
using namespace std;

int FibonacciMemoizationUtil(int n, vector<int> table) {
	if (n == 0 || n == 1) {
		return n;
	}
	if (table[n] != 0) {
		return table[n];
	}
	table[n] = FibonacciMemoizationUtil(n - 1, table) + FibonacciMemoizationUtil(n - 2, table);
	return table[n];
}

int FibonacciMemoization(int n) {
	vector<int> table(n + 1, 0);
	return FibonacciMemoizationUtil(n, table);
}