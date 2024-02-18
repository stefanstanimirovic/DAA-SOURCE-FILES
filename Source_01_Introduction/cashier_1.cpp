int cashier_1(int n, int h[]) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        bool ok = true;
        for (int j = 0; j < i; j++) {
            if (h[j] >= h[i]) {
                ok = false;
            }
        }
        if (ok == true) {
            count++;
        }
    }
    return count;
}