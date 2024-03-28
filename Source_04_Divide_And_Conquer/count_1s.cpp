int count1s(int a[], int n) {
    // ako je poslednji element niza nula,
    // tada niz ne sadrzi jedinice jer je sortiran
    if (a[n - 1] == 0) {
        return 0;
    }
 
    // ako je prvi element niza jedinica,
    // tada su svi elementi niza jedinice jer je sortiran
    if (a[0]) {
        return n;
    }
 
    // podeli niz na levu i desnu particiju i rekurzivno pozovi za particije
    return count(a, n/2) + count(a + n/2, n - n/2);
}
