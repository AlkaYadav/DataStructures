#include<iostream>
using namespace std;
class Node{
	int data;
	Node *next;
	friend class AdjacencyList;
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
};
