#pragma once
#include "Graph.h"
#include <queue>

class GraphTopSort : public Graph
{
public:
	GraphTopSort(int n = 0); // konstruisanje grafa

	// Dodavanje grane izmedju cvorova u i v (usmeren graf)
	void addEdgeDirected(int u, int v); 

	// Topolosko sortiranje (vraca true/false u zavisnosti da li postoji)
	bool TopSort(); 
};

