int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int gcd_it(int a, int b, int& x, int& y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        int q = a1 / b1;
        int xp = x, x1p = x1, yp = y, y1p = y1, a1p = a1, b1p = b1;
        x = x1p;
        x1 = xp - q * x1p;
        y = y1p;
        y1 = yp - q * y1p;
        a1 = b1p;
        b1 = a1p - q * b1p;
    }
    return a1;
}