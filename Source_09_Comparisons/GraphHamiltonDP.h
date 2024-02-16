#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <bitset>
using namespace std;

class GraphHamiltonDP
{
private:
    int V; // Broj cvorova
    vector<list<int>> adjList; // Lista susedstva
public:
    GraphHamiltonDP(int);
    // Konstruktor
    void addEdge(int, int);
    // Dodaj granu u graf
    bool hasEdge(int, int) const;
    // Provera da li postoji grana izmedju dva cvora
    bool hamiltonianPathDP();
    // Proveri postojanje Hamiltonovog puta u grafu
};

