int cashier_2(int n, int h[]) {
    int count = 0;
    int locmax = -1;
    for (int i = 0; i < n; i++) {
        if (h[i] > locmax) {
            count++;
            locmax = h[i];
        }
    }
    return count;
}