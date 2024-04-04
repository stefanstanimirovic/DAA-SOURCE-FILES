#pragma once
#include "Graph.h"
class GraphUndirected : public Graph
{
public:
	// Konstruisanje neusmerenog grafa
	GraphUndirected(int n = 0); 

	// Dodavanje grane izmedju cvorova u i v
	void addEdge(int u, int v); 
};

