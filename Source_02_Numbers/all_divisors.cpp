#include <vector>
using namespace std;

vector<int> allDivisors(int n) {
	vector<int> div;
	int i = 1;
	for (; i * i < n; i++) {
		if (n % i == 0) {
			div.push_back(i);
			div.push_back(n / i);
		}
	}
	if (i * i == n) {
		div.push_back(i);
	}
	return div;
}