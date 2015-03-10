#ifndef __Kruskal_H_INCLUDED__   // if x.h hasn't been included yet...
#define __Kruskal_H_INCLUDED__   //   #define this so the compiler knows it has been included
#include<iostream>
#include<stdlib.h>
using namespace std;
class Edge_Kruskal{
	int src;
	int dest;
	int weight;
	friend class Kruskal;
};
class Kruskal{
	int nodes;
	int edges;
	Edge_Kruskal *edge_kruskal;
	void sort_Graph();//Sort graph by edge weights
	static int cmpfunc(const void *a,const void *b);
	int find(Edge_Kruskal e,int *parent);
	void union_edge(Edge_Kruskal e,int *parent);
	void printKruskal(Edge_Kruskal*);
public:
	Kruskal(int node,int edge);
	void add_edge(int src,int dest,int weight);
	void printGraph();
	void KruskalMST();
};
#endif
