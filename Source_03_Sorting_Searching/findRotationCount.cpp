int findRotationCount(int n, int a[]) {
    int l = 0, r = n - 1;

    while (l <= r) {
        // ako je podniz vec sortiran, nasli
        // smo minimalni element (sa indeksom `l`)
        if (a[l] <= a[r]) {
            return l;
        }

        int m = (l + r) / 2;

        // nadji prethodnika i sledbenika elementa
        // sa indeksom `m` 
        int next = (m + 1) % n;
        int prev = (m - 1 + n) % n;

        // ako je element sa indeksom `mid` manji od
        // svog prethodnika i sledbenika, 
        // to je minimalni element niza

        if (a[m] <= a[next] && a[m] <= a[prev]) {
            return m;
        }

        // ako je a[m...r] soriran i a[m] nije minimalni element,
        // tada pivot ne moze biti u a[m...r],
        // odbacimo a[m...r] i pretrazimo levu polovinu
        else if (a[m] <= a[r]) {
            r = m - 1;
        }

        // ako je a[l...m] soritran i a[m] nije minimalni element,
        // tada pivot ne moze biti u a[l...m],
        // odbacimo a[l...m] i pretrazimo desnu polovinu
        else if (a[m] >= a[l]) {
            l = m + 1;
        }
    }

    // nevalidan input
    return -1;
}