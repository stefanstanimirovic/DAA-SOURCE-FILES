#include "Graph.h"

Graph::Graph(int n = 0) : numNodes(n), adj(n)
{}

void Graph::display() {
    for (int i = 0; i < numNodes; i++) {
        cout << "Cvor " << i << " je povezan sa: ";
        for (int neighbor : adj[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}