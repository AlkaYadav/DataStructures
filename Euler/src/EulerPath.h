#ifndef __EulerPath_H_INCLUDED__   // if x.h hasn't been included yet...
#define __EulerPath_H_INCLUDED__   //   #define this so the compiler knows it has been included
#include<list>
#include<iostream>
using namespace std;
class Graph{
	list<int> *adj;
	int nodes;
public:
	Graph(int nodes);
	void addEdge(int node1,int node2);
	void DFS(int src,int *visited);
	friend class EulerPath;
};
class EulerPath{

public:
	bool isEulerian(Graph);
	bool isConnected(Graph);
	bool hasEulerPath(Graph);
	void printEulerPathOrCircuit(Graph);
};
#endif
