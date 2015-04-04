#ifndef __HamiltonianCycle_H_INCLUDED__   // if x.h hasn't been included yet...
#define __HamiltonianCycle_H_INCLUDED__   //   #define this so the compiler knows it has been included
#include<list>
#include<iostream>
using namespace std;
#define V 5;
class Graph{
	int **adj;
	int nodes;

public:
	Graph(int nodes);
	void addEdge(int,int);
	void printGraph();
	friend class HamiltonianCycle;
};


class HamiltonianCycle{
	void printHamiltonianPath(Graph g,int*);
	bool isSafe(int node,int pos,Graph g,int *path);
	bool hamiltonianCycle(Graph g,int *path,int pos);
public:
	bool isHamiltonian(Graph);
};

#endif
