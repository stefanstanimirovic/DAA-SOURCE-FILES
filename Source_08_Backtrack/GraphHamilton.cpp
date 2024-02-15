#include "GraphHamilton.h"

GraphHamilton::GraphHamilton(int vertices) : V(vertices), adjList(vertices), path(V, -1) {}

// Dodaj granu u graf
void GraphHamilton::addEdge(int v, int w) {
    adjList[v].push_back(w);
    adjList[w].push_back(v);
}

// Rekurzivna pomocna funkcija za proveru Hamiltonovog puta
bool GraphHamilton::isHamiltonianPathUtil(int v, vector<int>& path, vector<bool>& visited, int& pathIndex) {
    visited[v] = true;
    path[pathIndex++] = v;

    // Ako su svi cvorovi dodati u put, nadjen je Hamiltonov put, nalazi se u parametru path
    if (pathIndex == V) {
        /*
        // Sledeci kod ispisuje Hamiltonov put
        cout << "Hamiltonov put: ";
        for (int j : path) {
            cout << j << " ";
        }
        cout << endl;
        */
        return true;
    }

    // Rekurzivno poseti sve susede trenutnog cvora koji nisu vec poseceni
    for (int u : adjList[v]) {
        if (!visited[u]) {
            if (isHamiltonianPathUtil(u, path, visited, pathIndex)) {
                return true;
            }
        }
    }

    // Ako nema puta iz trenutnog cvora, ponisti promene i vrati false
    visited[v] = false;
    pathIndex--;
    return false;
}

// Proveri postojanje Hamiltonovog puta u grafu
bool GraphHamilton::isHamiltonianPath() {
    vector<bool> visited(V, false); // Inicijalizuj niz za pracenje posecenih cvorova
    int pathIndex = 0; // Inicijalizuj indeks puta

    // Hamiltonov put pocinje od bilo kog cvora, pa proveri sve cvorove
    for (int i = 0; i < V; i++) {
        if (isHamiltonianPathUtil(i, path, visited, pathIndex)) {
            return true;
        }
    }

    // Ako nije pronadjen Hamiltonov put
    return false;
}

// Dohvatanje Hamiltonovog puta
vector<int> GraphHamilton::getHamiltonianPath() {
    return path;
}