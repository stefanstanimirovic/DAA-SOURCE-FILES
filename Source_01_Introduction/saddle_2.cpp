const int MAX_COLS = 10000;
#include <vector>
using namespace std;

bool saddle_point_2(int n, int m, int a[][MAX_COLS], int& pi, int& pj) {
	// Prekalkulacije: Racunamo na pocetku minimalni u svakoj vrsti i maksimalni u svakoj koloni
	vector<int> mins(n);
	vector<int> maxs(m);
	for (int i = 0; i < n; i++) {
		mins[i] = a[i][0];
		// Pretpostavka: prvi element iz vrste je minimalan u vrsti
	}
	for (int j = 0; j < m; j++) {
		maxs[j] = a[0][j];
		// Pretpostavka: prvi element iz kolone je maksimalan u koloni
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] < mins[i]) {
				mins[i] = a[i][j]; // Update: minimalni u vrsti i
			}
			if (a[i][j] > maxs[j]) {
				maxs[j] = a[i][j]; // Update: maksimalan u koloni j
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == mins[i] && a[i][j] == maxs[j]) {
				pi = i;
				pj = j;
				return true;
			}
		}
	}
	pi = -1;
	pj = -1;
	return false;
}