#ifndef __FordFulkerson_H_INCLUDED__   // if x.h hasn't been included yet...
#define __FordFulkerson_H_INCLUDED__   //   #define this so the compiler knows it has been included
#include <iostream>
#include <queue>
#define V 7
using namespace std;
class AdjacencyMatrix{
	int **adj;
	int node;

public:
	bool BFS(int src, int sink, int *parent, int a[][V]);
	AdjacencyMatrix(int nodes);
	void addEdge(int,int,int);
	void printAdjacencyMatrix();
	void printpath(int *, int src, int dest);
	friend class FordFulkerson;
};
class FordFulkerson{
public:
	int FordFulkersonAlgorithm(AdjacencyMatrix am,int src,int dest);
	void dfs(AdjacencyMatrix am,int residual[][V],int src,int *visited);
};
#endif
