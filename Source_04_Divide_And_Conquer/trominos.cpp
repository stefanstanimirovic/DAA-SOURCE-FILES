#include <iostream>
#include <vector>
using namespace std;

const int MAX = 128; // maximalna dimenzija table
int n; // dimenzija table
int a, b; // pozicija ostecenog polja
int cnt = 0; // brojac tromina
int tbl[MAX][MAX]; // tabla

// Postavljanje tri polja tromine na tablu
void setTromino(int x1, int y1, int x2, int y2, int x3, int y3) {
    cnt++;
    tbl[x1][y1] = cnt;
    tbl[x2][y2] = cnt;
    tbl[x3][y3] = cnt;
}

// redjanje tromina "podeli pa vladaj" algoritmom
// na tabli od x-te vrste do y-te kolone dimenzija n x n
// r i c predstavljaju koordinate zauzetog polja
// (ili je oscteceno ili je deo tromine na tom polju)
void arrangement(int n, int x, int y, int r, int c) {
    if (n == 2) { // granicni uslov za izlazak iz rekurzije
        // Tabla je dimenzija 2x2, postavi trominu na tri neostecena polja
        cnt++;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (tbl[x + i][y + j] == 0) {
                    tbl[x + i][y + j] = cnt;
                }
            }
        }
        return;
    }

    // Proveri u kom kvadrantu se nalazi zauzeto polje.
    // Kvadranti su numerisani na sledeci nacin:
    // 1   2
    // 3   4
    int half = n / 2;
    if (r < x + half && c < y + half) {
        // Ako je zauzeto polje u 1. kvadrantu
        setTromino(x + half, y + half - 1, x + half, y + half, x + half - 1, y + half);
        // Rekurzivno popuni trominama sva cetiri kvadranta
        arrangement(n / 2, x, y, r, c);
        arrangement(n / 2, x, y + half, x + half - 1, y + half);
        arrangement(n / 2, x + half, y, x + half, y + half);
        arrangement(n / 2, x + half, y + half, x + half, y + half - 1);
    }
    else if (r < x + n / 2 && c >= y + n / 2) {
        // Ako je zauzeto polje u 2. kvadrantu
        setTromino(x + half - 1, y + half - 1, x + half, y + half - 1, x + half, y + half);
        // Rekurzivno popuni trominama sva cetiri kvadranta
        arrangement(n / 2, x, y, x + half - 1, y + half - 1);
        arrangement(n / 2, x, y + half, r, c);
        arrangement(n / 2, x + half, y, x + half, y + half);
        arrangement(n / 2, x + half, y + half, x + half, y + half - 1);
    }
    else if (r >= x + n / 2 && c < y + n / 2) {
        // Ako je zauzeto polje u 3. kvadrantu
        setTromino(x + half - 1, y + half, x + half, y + half, x + half - 1, y + half - 1);
        // Rekurzivno popuni trominama sva cetiri kvadranta
        arrangement(n / 2, x, y, x + half - 1, y + half - 1);
        arrangement(n / 2, x, y + half, x + half - 1, y + half);
        arrangement(n / 2, x + half, y, r, c);
        arrangement(n / 2, x + half, y + half, x + half, y + half);
    }
    else if (r >= x + n / 2 && c >= y + n / 2) {
        // Ako je zauzeto polje u 4. kvadrantu
        setTromino(x + half - 1, y + half, x + half, y + half - 1, x + half - 1, y + half - 1);
        // Rekurzivno popuni trominama sva cetiri kvadranta
        arrangement(n / 2, x, y, x + half - 1, y + half - 1);
        arrangement(n / 2, x, y + half, x + half - 1, y + half);
        arrangement(n / 2, x + half, y, x + half, y + half - 1);
        arrangement(n / 2, x + half, y + half, r, c);
    }
    return;
}

// Glavni program koji testira funkciju
int tromino_main() {
    cin >> n; // ucitaj dimenzije table
    cin >> a >> b; // ucitaj koordinate ostecenog polja
    memset(tbl, 0, sizeof(tbl)); // popuni tablu nulama
    tbl[a][b] = -1; // na osteceno polje stavljamo -1
    arrangement(n, 0, 0, a, b); // na pocetku pozivamo redjanje tromina za celu tablu

    // Stampaj tablu
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << tbl[i][j] << " \t";
        }
        cout << "\n";
    }
    return 0;
}