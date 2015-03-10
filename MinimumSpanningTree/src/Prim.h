#ifndef __Prim_H_INCLUDED__   // if x.h hasn't been included yet...
#define __Prim_H_INCLUDED__   //   #define this so the compiler knows it has been included
#include<iostream>
using namespace std;
class Node{
	int data;
	int weight;
	Node *next;
	friend class AdjacencyList;
	friend class Prim;
};
class AdjacencyList{
	int node;
	Node** adjList;
public:
	AdjacencyList(int nodes);
	void add_edge_undirected(int origin,int dest,int weight);
	void add_edge_directed(int origin,int dest,int weight);
	void printAdjList();
	friend class Prim;
};

class Prim{
	int findMin(AdjacencyList al,int distance[],bool final_list[]);
public:
	void PrimAlgorithm(AdjacencyList al);
};
#endif
