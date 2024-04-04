#include <iostream>
#include <vector>
using namespace std;

class Mountain
{
private:
    vector<vector<double>> mountain; // nadmorske visine
    vector<vector<bool>> visited; // posecena polja
    int n, m; // dimenzije matrice
    int xS, yS; // pocetna polja skijasa
public:
    Mountain() {
        cout << "Unesite dimenzije matrice (n, m): ";
        cin >> n >> m;

        mountain = vector<vector<double>>(n, vector<double>(m));
        cout << "Unesite nadmorske visine za svako polje: " << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mountain[i][j];
            }
        }

        cout << "Unesite koordinate polaznog polja (x y): ";
        cin >> xS >> yS;
    }

    // DFS obilazak iz cvora (x, y)
    void DFSFromNode(int x, int y) {
        // Provera da li smo van granica ili je polje vec poseceno
        if (x < 0 || x >= n || y < 0 || y >= m || visited[x][y]) {
            return;
        }

        // Oznacavanje trenutnog polja kao posecenog
        visited[x][y] = true;

        // Pomeranje na susedna polja
        static int dx[] = { -1, 1, 0, 0 };
        static int dy[] = { 0, 0, -1, 1 };
        for (int i = 0; i < 4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            // Provera da li je susedno polje nize od trenutnog 
            // i da li je u granicama
            if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m 
                    && mountain[new_x][new_y] < mountain[x][y]) {
                DFSFromNode(new_x, new_y);
            }
        }
    }

    // Glavna funkcija koja racuna broj dostupnih polja za skijanje
    int countSkiFields() {
        // Sva polja su na pocetku neposecena
        visited = vector<vector<bool>>(n, vector<bool>(m, false));

        // Pokretanje DFS obilaska
        DFSFromNode(xS, yS);

        // Brojanje posecenih polja
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visited[i][j]) {
                    count++;
                }
            }
        }
        return count;
    }
};

int Mountain_main() {
    Mountain m;
    int count = m.countSkiFields();
    cout << count << endl;
    return 0;
}