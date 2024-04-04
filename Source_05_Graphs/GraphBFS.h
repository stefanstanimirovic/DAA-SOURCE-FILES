#pragma once
#include "GraphUndirected.h"
#include <queue>

class GraphBFS : public GraphUndirected 
{
protected:
    vector<bool> visited; // Markiranje posecenih cvorova
    vector<int> dist; // Rastojanja od startnog cvora
    vector<int> parent; // Roditelji u stablu BFS algoritma
public:
    GraphBFS(int n = 0); // Konstruisanje grafa
    void BFS(int startNode); // BFS algoritam iz datog cvora
};

