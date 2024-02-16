#include "GraphHamiltonDP.h"

GraphHamiltonDP::GraphHamiltonDP(int vertices) : V(vertices), adjList(vertices) {}

// Dodaj granu u graf
void GraphHamiltonDP::addEdge(int v, int w) {
    adjList[v].push_back(w);
    adjList[w].push_back(v);
}

// Provera da li postoji grana izmedju cvorova u i v u grafu
bool GraphHamiltonDP::hasEdge(int u, int v) const {
    auto it = std::find(adjList[u].begin(), adjList[u].end(), v);
    return it != adjList[u].end();
}

// Proveri postojanje Hamiltonovog puta u grafu
bool GraphHamiltonDP::hamiltonianPathDP() {
    vector<vector<bool>> dp(V, vector<bool>(1 << V, false));

    // Postavljanje pocetnih vrednosti
    for (int i = 0; i < V; i++) {
        dp[i][(1 << i)] = true;
    }

    // Iteracija kroz sve podskupove
    for (int i = 0; i < (1 << V); i++) {
        // Iteracija kroz sve zavrsne cvorove
        for (int j = 0; j < V; j++) {
            // Ako je j-ti cvor ukljucen u trenutni podskup
            if (i & (1 << j)) {
                // Nadji suseda k cvora j koji se takodje nalazi u podskupu
                for (int k = 0; k < V; k++) {
                    if (j != k && i & (1 << k) && hasEdge(k, j) && dp[k][i ^ (1 << j)] == 1) {
                        // Postavi dp[j][i] na true
                        dp[j][i] = true;
                        break;
                    }
                }
            }
        }
    }

    // Iteracija kroz cvorove
    for (int i = 0; i < V; i++) {
        if (dp[i][(1 << V) - 1]) {
            // cout << "Postoji Hamiltonov put ";
            return true;
        }
    }
    // cout << "Ne postoji Hamiltonov put ";
    return false;
}