#include<iostream>
using namespace std;

#include "GraphTopSort.h"

int GraphTopSort_main() {
    int numNodes = 7;
    GraphTopSort graph(numNodes);

    // Dodvanje grana izmedju cvorova
    graph.addEdgeDirected(0, 2);
    graph.addEdgeDirected(1, 2);
    graph.addEdgeDirected(1, 3);
    graph.addEdgeDirected(2, 4);
    graph.addEdgeDirected(2, 5);
    graph.addEdgeDirected(2, 6);
    graph.addEdgeDirected(3, 5);
    graph.addEdgeDirected(6, 5);

    graph.TopSort();

    return 0;
}