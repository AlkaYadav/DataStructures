#ifndef __FloyddWarshall_H_INCLUDED__   // if x.h hasn't been included yet...
#define __FloyddWarshall_H_INCLUDED__   //   #define this so the compiler knows it has been included

#include<iostream>
using namespace std;

class AdjacencyMatrix{
	int **adj;
	int node;
	friend class Floydd;

public:
	AdjacencyMatrix(int nodes);
	void addEdge(int,int,int);
	void printAdjacencyMatrix();
};

class Floydd{
public:
	void FloyddWarshallAlgorithm(AdjacencyMatrix am);
};
#endif
