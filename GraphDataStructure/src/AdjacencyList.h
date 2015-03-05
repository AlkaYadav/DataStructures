#ifndef __AdjacencyList_H_INCLUDED__   // if x.h hasn't been included yet...
#define __AdjacencyList_H_INCLUDED__   //   #define this so the compiler knows it has been included

#include<iostream>
using namespace std;
class Node{
	int data;
	Node *next;
	friend class AdjacencyList;
	friend class BFS;
	friend class DFS;
};
class AdjacencyList{
	int node;
	Node** adjList;
public:
	AdjacencyList(int nodes);
	void add_edge_undirected(int origin,int dest);
	void add_edge_directed(int origin,int dest);
	void del_edge_directed(int origin,int dest);
	void del_edge_undirected(int origin,int dest);
	void printAdjList();
	friend class BFS;
	friend class DFS;
};

#endif
