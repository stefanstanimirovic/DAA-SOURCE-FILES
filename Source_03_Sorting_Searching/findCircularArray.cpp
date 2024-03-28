int findCircularArray(int n, int a[], int x) {
    int l = 0, r = n - 1;

    while (l <= r) {
        int m = (l + r) / 2;

        if (a[m] == x) {
            return m;
        }

        // ako je desna polovina a[m...r] sortirana, i a[m] nije trazeni broj
        if (a[m] <= a[r]) {
            if (x > a[m] && x <= a[r]) {
                l = m + 1;      // trazi u desnoj sortiranoj polovini
            }
            else {
                r = m - 1;     // trazi u levoj polovini
            }
        }

        // ako je leva polovina a[l...m] sortirana, i a[m] nije trazeni broj
        else {
            if (x >= a[l] && x < a[m]) {
                r = m - 1;     // trazi u levoj sortiranoj polovini
            }
            else {
                l = m + 1;      // trazi u desnoj polovini
            }
        }
    }

    // ako trazeni broj ne postoji, vracamo -1
    return -1;
}