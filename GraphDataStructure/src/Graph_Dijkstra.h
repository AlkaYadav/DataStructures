#ifndef __Graph_Dijkstra_H_INCLUDED__   // if x.h hasn't been included yet...
#define __Graph_Dijkstra_H_INCLUDED__   //   #define this so the compiler knows it has been included
#include"Node_Dijkstra.h"
#include<iostream>
#include<limits>
using namespace std;
class Graph_Dijkstra{
	int node;
	Node_Dijkstra **adjList;
	int length(bool*);
	int findMin(int[],bool[]);
	void printShortestPath(int[],int sourcenode);
public:
	Graph_Dijkstra(int);
	void add_edge_directed_Djikstra(int node1,int node2,int weight);
	void Djikstra_Algorithm(int sourcenode);
};
#endif
