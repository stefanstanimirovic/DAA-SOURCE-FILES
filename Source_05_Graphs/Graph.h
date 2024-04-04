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
    // Inicijalizacija grafa na zadati broj cvorova
    Graph(int); 

    // Metoda za dodavanje grane izmedju cvorova u i v
    // Cisto virtuelna metoda koja ce drugacije biti implementirana
    // za usmerene i neusmerene grafove
    virtual void addEdge(int u, int v) = 0; 
    
    // Metoda za prikazivanje grafa
    void display(); 
};

