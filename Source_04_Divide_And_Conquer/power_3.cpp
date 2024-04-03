long power3(int a, int n, int m) {
    int res = 1;
    a = a % m;
    if (a == 0) {
        return 0;
    }
    while (n > 0) {
        if (n % 2 == 1) {
            res = (res * a) % m;
        }
        n = n / 2;
        a = (a * a) % m;
    }
    return res;
}