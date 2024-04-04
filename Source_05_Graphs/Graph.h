#pragma once
#include <vector>
#include <iostream>
using namespace std;

class Graph
{
protected:
    int numNodes; // Broj cvorova u grafu
    vector<vector<int>> adj; // Lista susedstva
public:
    Graph(int); // inicijalizacija grafa na zadati broj cvorova
    void addEdge(int u, int v); // Dodavanje grane izmedju cvorova u i v
    void display(); // Prikazivanje grafa
};

