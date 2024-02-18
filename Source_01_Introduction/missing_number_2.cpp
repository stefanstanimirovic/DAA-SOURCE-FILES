#include <vector>
using namespace std;

int missing_number_2(int n, int a[]) {
	vector<bool> flag(n + 1, false);
	for (int i = 0; i < n; i++) {
		flag[a[i]] = true;
	}
	int result = -1;
	for (int i = 0; i <= n; i++) {
		if (!flag[i]) {
			result = i;
			break;
		}
	}
	return result;
}