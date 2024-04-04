#include "Graph.h"

Graph::Graph(int n = 0) : numNodes(n), adj(n)
{}

// Dodavanje grane izmedju cvorova u i v
void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u); // Bez ovog reda graf je usmeren
}

// Prikazivanje grafa
void Graph::display() {
    for (int i = 0; i < numNodes; i++) {
        cout << "Cvor " << i << " je povezan sa: ";
        for (int neighbor : adj[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}