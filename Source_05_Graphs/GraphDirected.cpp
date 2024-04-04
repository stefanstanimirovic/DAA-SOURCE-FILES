#include "GraphDirected.h"

// Konstruisanje usmerenog grafa
GraphDirected::GraphDirected(int n) : Graph(n)
{ }

// Dodavanje grane izmedju cvorova u i v
// Usmeren graf ima granu izmedju cvorova u i v
void GraphDirected::addEdge(int u, int v) {
    adj[u].push_back(v);
}