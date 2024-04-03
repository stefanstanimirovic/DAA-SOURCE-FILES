long power1(int a, int n, int m) {
    long pow = 1;
    for (int i = 0; i < n; i++) {
        pow = (pow * a) % m;
    }
    return pow;
}