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
	void rmEdge(int node1,int node2);
	void printGraph();
	friend class EulerPath;
};
class EulerPath{
private:
	bool isConnected(Graph);
	int DFSCount(Graph g,int,int *);
	void printEulerPathOrCircuitUtil(Graph g,int source);
	bool isValidNextEdge(Graph g,int source,int dest);
public:
	bool isEulerian(Graph);
	void printEulerPathOrCircuit(Graph g);
};
#endif
