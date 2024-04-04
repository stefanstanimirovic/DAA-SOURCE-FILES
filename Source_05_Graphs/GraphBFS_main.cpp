#include<iostream>
using namespace std;

#include "GraphBFS.h"

int GraphBFS_main() {
    int numNodes = 7;
    GraphBFS graph(numNodes);

    // Dodvanje grana izmedju cvorova
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    graph.addEdge(2, 5);
    graph.addEdge(2, 6);
    graph.addEdge(3, 4);
    graph.addEdge(3, 5);
    graph.addEdge(3, 6);

    int startNode = 0; // pocetni cvor
    graph.BFS(startNode);

    return 0;
}