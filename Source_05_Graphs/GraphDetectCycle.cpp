#include "GraphDetectCycle.h"

GraphDetectCycle::GraphDetectCycle(int n) : GraphUndirected(n), visited(n), parent(n)
{}

bool GraphDetectCycle::DetectCycleFromNode(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            parent[v] = u;
            if (DetectCycleFromNode(v)) {

                return true;
            }
        }
        else if (v != parent[u]) {
            return true;
        }
    }
    return false;
}

bool GraphDetectCycle::DetectCycle() {
    visited = vector<bool>(numNodes, false);
    for (int u = 0; u < numNodes; u++) {
        if (!visited[u]) {
            if (DetectCycleFromNode(u)) {
                return true;
            }
        }
    }
    return false;
}