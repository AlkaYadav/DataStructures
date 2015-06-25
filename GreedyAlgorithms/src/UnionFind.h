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
	int weight;
	friend class Graph_EdgeList;
	friend class UnionFind;
	friend class KruskalMST;
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
	friend class KruskalMST;
};

class UnionFind{
private:
	int find(int *parent,int node);
	void unionVertices(int *parent,int node1,int node2);

	//Union find algorithm using union by rank and path compression
	int find_pathcompression(int *parent,int node);
	void unionVertices_rank(int *parent,int *rank,int node1,int node2);

public:
	int isCycle(Graph_EdgeList ge);

	//Detect cycle in undirected graph using union by rank and path compression
	int isCycle_UnionByRankPathCompression(Graph_EdgeList ge);
	friend class KruskalMST;
};

#endif /* UNIONFIND_H_ */
