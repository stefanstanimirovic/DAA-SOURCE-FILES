#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class FireSpread
{
private:
    vector<vector<char>> grid;
    int n, m;
    bool isValid(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }
public:
    FireSpread(vector<vector<char>> grid): grid(grid) {
        n = grid.size();
        m = grid[0].size();
    }

    // Funkcija koja nalazi minimalno vreme potrebno da se cela tabla zapali
    int calculate() {
        queue<pair<int, int>> fire;

        // Dodavanje pocetnih pozara u red
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 'V') {
                    fire.push({ i, j });
                }
            }
        }

        // Kretanje u susedna polja i sirenje vatre
        int seconds = 0;
        while (!fire.empty()) {
            int size = fire.size();
            for (int i = 0; i < size; ++i) {
                int currentX = fire.front().first;
                int currentY = fire.front().second;
                fire.pop();

                // Pomeranje na susedna polja
                int dx[] = { 0, 0, 1, -1 };
                int dy[] = { 1, -1, 0, 0 };
                for (int j = 0; j < 4; ++j) {
                    int newX = currentX + dx[j];
                    int newY = currentY + dy[j];
                    if (isValid(newX, newY) && grid[newX][newY] == '.') {
                        grid[newX][newY] = 'V'; // Oznacavanje kao zahvaceno vatrom
                        fire.push({ newX, newY });
                    }
                }
            }
            seconds++;
        }

        return seconds - 1; // Poslednju sekundu ne treba racunati
    }
};

int FireSpread_main() {
    // Primer
    vector<vector<char>> grid = {
        {'V', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', 'V'}
    };
    vector<vector<char>> grid2 = {
        {'.', '.', '.', '.', '.', '.', '.'},
        {'.', 'V', '.', 'V', '.', '.', '.'},
        {'.', 'V', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', 'V'}
    };

    FireSpread fs(grid);
    cout << fs.calculate() << endl;

    return 0;
}
