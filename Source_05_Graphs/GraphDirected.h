#pragma once
#include "Graph.h"
class GraphDirected : public Graph
{
public:
	// Konstruisanje usmerenog grafa
	GraphDirected(int n = 0);

	// Dodavanje grane izmedju cvorova u i v
	void addEdge(int u, int v);
};

