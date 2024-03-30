void swap(int& a, int& b);

void partitionQuick(int a[], int n) {
    int pIndex = 0;

    // svaki put kada pronadjemo negativan broj, 'pIndex' se povecava,
    // a taj element ide ispred stozera
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {   // 0 je stozer
            swap(a[i], a[pIndex]);
            pIndex++;
        }
    }
}