#include <iostream>
#include <vector>
using namespace std;

int maxNumberOfThieves1(char a[], int n, int k) {
    int count = 0;
    vector<int> pol; // pozicije policajaca
    vector<int> lop; // pozicije lopova

    // Razdvajanje pozicija policajaca i lopova u dva vektora
    for (int i = 0; i < n; i++) {
        if (a[i] == 'P') {
            pol.push_back(i);
        }
        else {
            lop.push_back(i);
        }
    }

    // Upari lopove i policajce
    int iP = 0, iL = 0;
    while (iP < pol.size() && iL < lop.size()) {
        // Proveriti da li je trenutni lopov na razdaljini manjoj od K od trenutnog policajca
        if (abs(pol[iP] - lop[iL]) <= k) {
            count++;
            iP++;
            iL++;
        }
        else if (pol[iP] < lop[iL]) {
            iP++;
        }
        else {
            iL++;
        }
    }
    return count;
}

int Thieves_main() {
    int n, k;

    // Test primeri
    char arr1[] = { 'L', 'P', 'P', 'P', 'L', 'L', 'L' };
    k = 2;
    n = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Broj uhvacenih lopova: " << maxNumberOfThieves1(arr1, n, k) << endl;

    char arr2[] = { 'L', 'L', 'P', 'P', 'L', 'P' };
    k = 2;
    n = sizeof(arr2) / sizeof(arr2[0]);
    cout << "Broj uhvacenih lopova: " << maxNumberOfThieves1(arr2, n, k) << endl;

    char arr3[] = { 'P', 'L', 'P', 'L', 'L', 'P' };
    k = 3;
    n = sizeof(arr3) / sizeof(arr3[0]);
    cout << "Broj uhvacenih lopova: " << maxNumberOfThieves1(arr3, n, k) << endl;
    return 0;
}