#pragma once
#include "GraphUndirected.h"
class GraphDetectCycle : public GraphUndirected
{
protected:
	vector<bool> visited; 
	vector<int> parent;
public:
	GraphDetectCycle(int n = 0); // Konstruisanje grafa
	bool DetectCycleFromNode(int u); // DFS algoritam iz datog cvora u
	bool DetectCycle(); // DFS algoritam za ceo graf
};

