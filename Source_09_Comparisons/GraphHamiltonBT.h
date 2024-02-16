#pragma once
#include <iostream>
#include <vector>
#include <list>
using namespace std;

class GraphHamiltonBT {
private:
    int V; // Broj cvorova
    vector<list<int>> adjList; // Lista susedstva
    vector<int> path; // Hamiltonov put (ukoliko postoji)
public:
    GraphHamiltonBT(int);
    // Konstruktor
    void addEdge(int, int);
    // Dodaj granu u graf
    bool isHamiltonianPathUtil(int v, vector<int>& path, vector<bool>& visited, int& pathIndex);
    // Rekurzivna pomocna funkcija za proveru Hamiltonovog puta
    bool isHamiltonianPath();
    // Proveri postojanje Hamiltonovog puta u grafu
    vector<int> getHamiltonianPath();
    // Dohvatanje Hamiltonovog puta
};