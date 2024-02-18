void shift_k_1(int n, int m, int a[]) {
    for (int k = 1; k <= m; k++) { // m puta rotiramo niz za jedno mesto ulevo
        int t = a[0];
        for (int i = 0; i < n - 1; i++) {
            a[i] = a[i + 1];
        }
        a[n - 1] = t;
    }
}