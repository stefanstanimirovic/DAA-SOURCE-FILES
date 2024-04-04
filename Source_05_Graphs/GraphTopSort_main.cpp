#include<iostream>
using namespace std;

#include "GraphTopSort.h"

int GraphTopSort_main() {
    int numNodes = 7;
    GraphTopSort graph(numNodes);

    // Dodvanje grana izmedju cvorova
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(2, 5);
    graph.addEdge(2, 6);
    graph.addEdge(3, 5);
    graph.addEdge(6, 5);

    graph.TopSort();

    return 0;
}