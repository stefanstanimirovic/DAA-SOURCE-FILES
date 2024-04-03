long power2(int a, int n, int m) {
    // Granicni slucajevi
    if (a == 0) {
        return 0;
    }
    if (n == 0) {
        return 1;
    }

    // Rekurzivna formula
    long y;
    if (n % 2 == 0) {
        y = power2(a, n / 2, m);
        y = (y * y) % m;
    }
    else {
        y = a % m;
        y = (y * power2(a, n - 1, m)) % m;
    }
    return y;
}