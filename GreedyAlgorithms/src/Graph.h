#include<iostream>
#include<stdio.h>
using namespace std;
//Graph uses Adjacency List
class Node{
	int data;
	Node *next;
	friend class Graph;
};

class Graph{
	int numberOfNodes;
	Node **vertices;
	void insertEdge_directedHelper(int source, int destination);
public:
	Graph(int numberOfNodes);
	void insertEdge_undirected(int source, int destination);
	void deleteEdge_undirected(int source, int destination);
	void printGraph();
};
