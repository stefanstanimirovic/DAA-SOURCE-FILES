#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Stocar {
    int litara;
    int cena;
};

bool compare(const Stocar& a, const Stocar& b) {
    return a.cena < b.cena; // Sortiranje po ceni u neopadajucem poretku
}

int minimumNovca(vector<Stocar> stocari, int k) {
    sort(stocari.begin(), stocari.end(), compare); // Sortiranje mlekara po ceni

    int minNovca = 0;
    int litaraKupljeno = 0;

    for (int i = 0; i < stocari.size(); i++) {
        // Koliko litara mozemo kupiti od trenutnog stocara
        int litaraTrenutne = min(k - litaraKupljeno, stocari[i].litara);
        minNovca += litaraTrenutne * stocari[i].cena;
        litaraKupljeno += litaraTrenutne;

        // Ako smo kupili dovoljno litara, izlazimo iz petlje
        if (litaraKupljeno >= k)
            break;
    }
    return minNovca;
}

int Stocari_main() {
    int n, k;
    cin >> n >> k;
    vector<Stocar> stocari(n);
    for (int i = 0; i < n; i++) {
        cin >> stocari[i].litara >> stocari[i].cena;
    }
    int minNovca = minimumNovca(stocari, k);
    cout << minNovca << endl;
    return 0;
}