#include "DFS.h"
#include "AdjacencyList.h"
#include<iostream>
using namespace std;
DFS::DFS(AdjacencyList al){
	visited=new bool[al.node];
	for(int i=0;i<al.node;i++){
		visited[i]=0;
	}
}
void DFS::DFS_Graph(AdjacencyList al,int sourcenode){
	Node *tmp=al.adjList[sourcenode];
	cout<<sourcenode<<"->";
	while(tmp){
		if(visited[tmp->data]==0){

			visited[tmp->data]=1;
			DFS_Graph(al,tmp->data);
		}
		tmp=tmp->next;
	}
}
