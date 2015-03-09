#ifndef __BellmanFord_H_INCLUDED__   // if x.h hasn't been included yet...
#define __BellmanFord_H_INCLUDED__   //   #define this so the compiler knows it has been included
#include<iostream>
using namespace std;
class Edge_Bellman{
	int src;
	int dest;
	int weight;
	friend class BellmanFord;
};

class BellmanFord{
	int vertices;
	int edge;
	Edge_Bellman **edge_array;
	void printDistanceArray(int []);
	void printParentArray(int []);
	bool checkNegativeCycle(int []);
public:
	BellmanFord(int vertices,int edges);
	void add_edge(int src,int dest,int weight);
	void printGraph();
	void BellmanFordAlgorithm(int source);
	void printShortestPathForAllVertices(int *parent,int source);
};
#endif
