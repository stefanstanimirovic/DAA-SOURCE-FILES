#include<iostream>
using namespace std;

#include "Source_05_Graphs/Graph.h"

int main() {
    int numNodes = 7;
    Graph graph(numNodes);

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

    // Prikazivanje grafa
    graph.display();

    return 0;
}