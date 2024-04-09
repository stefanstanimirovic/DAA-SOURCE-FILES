#include <iostream>
using namespace std;

int maxNumberOfThieves2(char a[], int n, int k) {
    // Inicijalizirajte trenutne najnize indekse
    // policajca i lopov u promenljivama kao -1
    int iP = -1, iL = -1, count = 0;

    // Pronadji najnizi indeks policajaca
    for (int i = 0; i < n; i++) {
        if (a[i] == 'P') {
            iP = i;
            break;
        }
    }

    // Pronadji najnizi indeks lopova
    for (int i = 0; i < n; i++) {
        if (a[i] == 'L') {
            iL = i;
            break;
        }
    }

    if (iL == -1 || iP == -1) {
        return 0;
    }
    while (iP < n && iL < n) {
        if (abs(iP - iL) <= k) {
            for (iP++; iP < n && a[iP] != 'P'; iP++);
            for (iL++; iL < n && a[iL] != 'L'; iL++);
            count++;
        }
        else if (iL < iP) {
            for (iL++; iL < n && a[iL] != 'L'; iL++);
        }
        else {
            for (iP++; iP < n && a[iP] != 'P'; iP++);
        }
    }
    return count;
}