#include "DFS.h"
#include "AdjacencyList.h"
#include<iostream>
using namespace std;
void DFS::DFS_Graph(AdjacencyList al){
	color=new char[al.node];
	parent=new int[al.node];
	discovery=new int[al.node];
	finish=new int[al.node];
	for(int i=0;i<al.node;i++){
		color[i]='W';
		parent[i]=-1;
	}
	time_v=0;
	for(int i=0;i<al.node;i++){
		if(color[i]=='W'){
			DFS_Visit(al,i);
		}
	}
}

void DFS::DFS_Visit(AdjacencyList al,int sourcenode){
	time_v=time_v+1;
	color[sourcenode]='G';
	discovery[sourcenode]=time_v;
	cout<<" ( "<<sourcenode;
	Node *tmp=al.adjList[sourcenode];
	while(tmp){
		if(color[tmp->data]=='W'){
			parent[tmp->data]=sourcenode;
			DFS_Visit(al,tmp->data);
		}
		tmp=tmp->next;
	}
	color[sourcenode]='B';
	time_v=time_v+1;
	finish[sourcenode]=time_v;
	cout<<sourcenode<<" ) ";
}
