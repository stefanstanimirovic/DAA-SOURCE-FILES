int numberOfCoins2(int x, int c) {
    int e = 1;
    while (e * c <= x) {
        e = e * c;
    }

    int result = 0;
    while (x > 0) {
        result = result + (x / e);
        x = x % e;
        e = e / c;
    }
    return result;
}