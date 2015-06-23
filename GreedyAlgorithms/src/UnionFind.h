/*
 * UnionFind.h
 *
 *  Created on: Jun 22, 2015
 *      Author: alkyadav
 */

#ifndef UNIONFIND_H_
#define UNIONFIND_H_
#include<iostream>
using namespace std;

//Graph uses Edge List
class Edge{
	int source;
	int destination;
	friend class Graph_EdgeList;
	friend class UnionFind;
};

class Graph_EdgeList{
	int vertices;
	int edgeCount;
	Edge **edges;
public:
	Graph_EdgeList(int vertices, int edgeCount);
	void addEdges();
	void printGraph();
	friend class UnionFind;
};

class UnionFind{
private:
	int find(int *parent,int node);
	void unionVertices(int *parent,int node1,int node2);

public:
	int isCycle(Graph_EdgeList ge);
};

#endif /* UNIONFIND_H_ */
