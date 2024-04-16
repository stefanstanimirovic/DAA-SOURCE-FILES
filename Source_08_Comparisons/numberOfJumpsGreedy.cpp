#include <iostream>
using namespace std;

int numberOfJumpsGreedy(int a[], int n) {
    if (n <= 1) {
        // Ako je niz a prazan ili ima samo jedan element, 
        // dosli smo do kraja niza sa 0 skokova
        return 0;
    }
    if (a[0] == 0) {
        // Ako je prvi element niza a jednak 0, ne mozemo da skacemo dalje
        return -1;
    }

    int maxDostizniIndex = a[0]; // Maksimalno dostizni indeks u trenutnom skoku
    int korak = a[0]; // Broj listova koje mozemo da preskocimo iz trenutnog indeksa
    int brojSkokova = 1; // Broj skokova do sada

    for (int i = 1; i < n; i++) {
        if (i == n - 1) {
            // Ako smo dosli do kraja niza, vrati broj skokova
            return brojSkokova;
        }

        // Azuriramo maksimalni indeks dostizan iz trenutnog indeksa
        maxDostizniIndex = max(maxDostizniIndex, i + a[i]);

        // Smanjimo broj koraka potrebnih da se dodje do trenutnog indeksa
        korak--;

        if (korak == 0) {
            // Ako vise ne mozemo ni jedan korak da napravimo iz trenutnog
            //  indeksa, potrebno je napraviti novi skok
            brojSkokova++; // povecamo broj skokova
            if (i >= maxDostizniIndex) {
                // Ako je trenutni indeks veci od maksimalno dostiznog indeksa, 
                // vrati -1
                return -1;
            }

            // Azuriramo broj koraka koje mozemo napraviti iz trenutnog indeksa
            korak = maxDostizniIndex - i;
        }
    }
    return -1; // Ako nismo dosli do kraja niza, vrati -1
}