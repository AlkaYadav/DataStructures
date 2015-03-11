#ifndef __GraphColoring_H_INCLUDED__   // if x.h hasn't been included yet...
#define __GraphColoring_H_INCLUDED__   //   #define this so the compiler knows it has been included

#include<iostream>
using namespace std;
class AdjacencyMatrix{
	int **adj;
	int node;

public:
	AdjacencyMatrix(int nodes);
	void addEdge(int,int);
	void printAdjacencyMatrix();
	friend class GraphColoring;
};

class GraphColoring{
	bool test_for_color_validity(AdjacencyMatrix am,int *color,int vertex,int m,int);
public:
	void GraphColoringAlgorithm(AdjacencyMatrix ,int color);
};

#endif
