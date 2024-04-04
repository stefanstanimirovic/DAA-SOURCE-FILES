#include "GraphBFS.h"

GraphBFS::GraphBFS(int n) : Graph(n), visited(n), dist(n), parent(n)
{}

void GraphBFS::BFS(int startNode) {
    // Na pocetku su svi cvorovi neposeceni
    visited = vector<bool>(numNodes, false);
    dist = vector<int>(numNodes, -1);
    parent = vector<int>(numNodes, -1);

    queue<int> q; // Red za smestanje cvorova za obilazak
    q.push(startNode); // Dodajemo pocetni cvor u red
    visited[startNode] = true; // Oznacavamo pocetni cvor kao posecen
    dist[startNode] = 0; // Rastojanje od pocetnog cvora je 0

    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();
        cout << currentNode << " ";

        // Prolazimo kroz susede cvora currentNode, 
        // i dodajemo ih u red ako nisu poseceni
        for (int neighbor : adj[currentNode]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
                parent[neighbor] = currentNode;
                dist[neighbor] = dist[currentNode] + 1;
            }
        }
    }
}