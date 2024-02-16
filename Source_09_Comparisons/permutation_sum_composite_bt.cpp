#include <iostream>
#include <vector>
using namespace std;

// Import class GraphHamilton
#include "GraphHamiltonBT.h"

// Imports from other files
vector<bool> eratosten(int n);

bool permutation_sum_composite_bt(int n, int m) {
    vector<bool> sito = eratosten(2 * m - 1);
    GraphHamiltonBT g(m - n + 1);
    for (int i = n; i <= m - 1; i++) {
        for (int j = i + 1; j <= m; j++) {
            if (sito[i + j] == false) {
                g.addEdge(i - n, j - n);
            }
        }
    }
    if (g.isHamiltonianPath()) {
        vector<int> path = g.getHamiltonianPath();
        for (int j : path) {
            cout << j + n << " ";
        }
        return true;
    }
    else {
        cout << -1;
        return false;
    }
}