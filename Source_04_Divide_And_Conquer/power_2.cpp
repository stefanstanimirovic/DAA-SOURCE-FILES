long power2(int a, int n, int m) {
    // Granicni slucajevi
    if (a == 0) {
        return 0;
    }
    if (n == 0) {
        return 1;
    }

    // Rekurzivna formula
    long temp = power2(a, n / 2, m);
    if (n % 2 == 0) {
        return (temp * temp) % m;
    }
    return (((a % m) * temp) % m * temp) % m;
}