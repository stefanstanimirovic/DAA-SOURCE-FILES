#pragma once
#include "GraphDirected.h"
#include <queue>

class GraphTopSort : public GraphDirected
{
public:
	GraphTopSort(int n = 0); // konstruisanje grafa

	// Topolosko sortiranje (vraca true/false u zavisnosti da li postoji)
	bool TopSort(); 
};

