#include <vector>
using namespace std;

void shift_k_2(int n, int m, int a[]) {
    m = m % n;
    vector<int> b(n);
    // 1. Y se sa kraja niza a prebacuje na pocetak niza b
    for (int i = 0; i < n - m; i++) {
        b[i] = a[m + i];
    }
    // 2. X se prebacuje sa pocetka niza a na kraj niza b
    for (int i = n - m; i < n; i++) {
        b[i] = a[i - (n - m)];
    }
    // 3. ceo niz b se prebacuje u niz a
    for (int i = 0; i < n; i++) {
        a[i] = b[i];
    }
}