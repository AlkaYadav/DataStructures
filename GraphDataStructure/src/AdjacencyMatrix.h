#include<iostream>
using namespace std;
class AdjacencyMatrix{
	int **adj;
	int node;

public:
	AdjacencyMatrix(int nodes);
	void addEdge(int,int);
	void printAdjacencyMatrix();
};
