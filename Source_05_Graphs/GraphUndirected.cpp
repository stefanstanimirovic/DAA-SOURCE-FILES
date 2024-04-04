#include "GraphUndirected.h"

// Konstruisanje neusmerenog grafa
GraphUndirected::GraphUndirected(int n) : Graph(n)
{ }

// Dodavanje grane izmedju cvorova u i v
// Neusmeren graf ima granu izmedju cvorova u i v,
// kao i izmedju cvorova v i u
void GraphUndirected::addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u); // Bez ovog reda graf je usmeren
}