#include "GraphDFS.h"

GraphDFS::GraphDFS(int n) : Graph(n), visited(n) 
{}

void GraphDFS::DFSFromNode(int u){
    // Oznacavamo trenutni cvor kao posecen
    visited[u] = true;
    cout << u << " ";

    // Prodjemo kroz sve susede cvora u i pozivamo DFS za neposecene susede
    for (int neighbor : adj[u]) {
        // Ako sused nije posecen, pustimo DFS algoritam iz tog cvora
        if (!visited[neighbor]) {
            DFSFromNode(neighbor);
        }
    }
}

void GraphDFS::DFS() {
    // Na pocetku markiramo sve cvorove kao neposecene
    visited = vector<bool>(numNodes, false);

    // Prodjemo kroz sve cvorove, te za svaki neposeceni cvor
    // pozivamo DFS iz tog cvora
    for (int i = 0; i < numNodes; i++) {
        if (!visited[i]) {
            DFSFromNode(i);
        }
    }
}