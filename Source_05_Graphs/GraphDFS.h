#pragma once
#include "Graph.h"
class GraphDFS : public Graph {
protected:
	vector<bool> visited; // Markiranje posecenih cvorova
public:
	GraphDFS(int n = 0); // Konstruisanje grafa
	void DFSFromNode(int u); // DFS algoritam iz datog cvora u
	void DFS(); // DFS algoritam za ceo graf
};

