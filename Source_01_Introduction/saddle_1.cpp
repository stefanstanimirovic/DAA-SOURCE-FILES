const int MAX_COLS = 10000;

bool saddle_point_1(int n, int m, int a[][MAX_COLS], int& pi, int& pj) {
	// Prolazimo kroz sve elemente matrice, i proveravamo da li je
	// tekuci element minimalan u vrsti i maksimalan u koloni
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// mini - minimalni element u vrsti i
			int mini = a[i][0];
			for (int k = 1; k < m; k++) {
				if (a[i][k] < mini) {
					mini = a[i][k];
				}
			}
			// maxj - maksimalni element u koloni j
			int maxj = a[0][j];
			for (int k = 1; k < n; k++) {
				if (a[k][j] > maxj) {
					maxj = a[k][j];
				}
			}
			// da li je a[i][j] sedlo
			if (a[i][j] == mini && a[i][j] == maxj) {
				pi = i;
				pj = j;
				return true;
			}
		}
	}
	// Ako smo prosli kroz sve elemente matrice, znaci da matrica ne poseduje sedlo
	pi = -1;
	pj = -1;
	return false;
}