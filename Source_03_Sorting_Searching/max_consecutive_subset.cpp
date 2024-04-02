#include <vector>
#include <algorithm>
using namespace std;

vector<int> maxConsecutiveSubset(int a[], int n) {
    sort(a, a + n); // Sortiraj niz
    int maxCount = 1, currentCount = 1;
    int startIndex = 0, maxStartIndex = 0;

    // Proveri za svaki par susjednih brojeva
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1] + 1) { // Ako su uzastopni
            currentCount++;
            if (currentCount > maxCount) { // Azuriraj maksimalni broj i indeks pocetka
                maxCount = currentCount;
                maxStartIndex = startIndex;
            }
        }
        else {
            startIndex = i; // Postavi novi pocetak podniza
            currentCount = 1; // Resetuj brojac
        }
    }

    // Rekonstruisi rezultat na osnovu maksimalnog podskupa
    vector<int> result;
    for (int i = maxStartIndex; i < maxStartIndex + maxCount; i++) {
        result.push_back(a[i]);
    }
    return result;
}