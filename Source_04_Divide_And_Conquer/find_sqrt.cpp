int findSqrt(int n) {
    if (n < 2) {
        return n;
    }

    int res, l = 1, r = n / 2;
    while (l <= r) {
        int m = l + (r - l) / 2;
        long sqr = m * m;
        if (sqr == n) {
            return sqr;
        }
        else if (sqr < n) {
            l = m + 1;
            res = m;
        }
        else {
            r = m - 1;
        }
    }
    return res;
}