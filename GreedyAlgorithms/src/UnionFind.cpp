/*
 * UnionFind.cpp
 *
 *  Created on: Jun 23, 2015
 *      Author: alkyadav
 */

#include "UnionFind.h"

Graph_EdgeList::Graph_EdgeList(int vertices,int numberOfEdges){
	this->vertices=vertices;
	this->edgeCount=numberOfEdges;//Increase edge count as edges are added subsequently
	edges=new Edge[numberOfEdges];
}

//Add edges in edge list
void Graph_EdgeList::addEdges(){
	int source,destination,weight;
	for(int i=0;i<edgeCount;i++){
		cout<<"Enter source vertex"<<endl;
		cin>>source;
		cout<<"Enter destination vertex"<<endl;
		cin>>destination;
		cout<<"Enter weight of edge"<<endl;
		cin>>weight;
		if(source<0 || source>vertices-1 || destination<0 || destination>vertices-1|| weight<0){
				cout<<"Invalid weight or Invalid source or destination.Insert in range 0 to "<<vertices-1<<endl;
				i--;
			}
		else{
			//TODO:Avoid adding duplicate edges
			//TODO:Identify adding an undirected edge and directed edge
			edges[i].source=source;
			edges[i].destination=destination;
			edges[i].weight=weight;
			cout<<"Inserted edge"<<endl;
		}
	}
}

void Graph_EdgeList::printGraph(){
	for(int i=0;i<edgeCount;i++){
		cout<<edges[i].source<<"->"<<edges[i].destination<<"Weight:"<<edges[i].weight<<endl;
	}
}


//Detect cycle using Union-find algorithm
int UnionFind::isCycle(Graph_EdgeList ge){
	int *parent=new int[ge.vertices];
	for(int i=0;i<ge.vertices;i++){
		parent[i]=-1;
	}
	for(int j=0;j<ge.edgeCount;j++){
		int source=ge.edges[j].source;
		int destination=ge.edges[j].destination;
		int xfind=find(parent,source);
		int yfind=find(parent,destination);
		if(xfind==yfind){
			cout<<"Cycle detected"<<endl;
			return 1;
		}
		unionVertices(parent,source,destination);
	}
	return 0;
}

int UnionFind::find(int *parent,int node){
	if(parent[node]==-1){
		return node;
	}
	return find(parent,parent[node]);
}

void UnionFind::unionVertices(int *parent,int node1,int node2){
	int xfind=find(parent,node1);
	int yfind=find(parent,node2);
	parent[yfind]=xfind;
}


//Detect cycle using Union-find algorithm using union by rank and path compression
int UnionFind::isCycle_UnionByRankPathCompression(Graph_EdgeList ge){
	int *parent,*rank;
	parent=new int[ge.vertices];
	rank=new int[ge.vertices];
	for(int i=0;i<ge.vertices;i++){
		parent[i]=-1;
		rank[i]=0;
	}
	for(int j=0;j<ge.edgeCount;j++){
		int source=ge.edges[j].source;
		int destination=ge.edges[j].destination;
		int xfind=find_pathcompression(parent,source);
		int yfind=find_pathcompression(parent,destination);
		if(xfind==yfind){
			cout<<"Cycle detected"<<endl;
			return 1;
		}
		unionVertices_rank(parent,rank,source,destination);
	}
	return 0;
}


int UnionFind::find_pathcompression(int *parent,int node){
	if(parent[node]==-1){
		return node;
	}
	return find_pathcompression(parent,parent[node]);
}


void UnionFind::unionVertices_rank(int *parent,int *rank,int node1,int node2){
	int xfind=find_pathcompression(parent,node1);
	int yfind=find_pathcompression(parent,node2);

	if(rank[node1]<rank[node2]){
		parent[xfind]=yfind;
	}
	else if(rank[node1]>rank[node2]){
		parent[yfind]=xfind;
	}
	else if(rank[node1]==rank[node2]){
		parent[xfind]=yfind;
		rank[node2]=rank[node2]+1;
	}
}
