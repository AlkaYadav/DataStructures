#include"AdjacencyMatrix.h"
#include "AdjacencyList.h"
#include "BFS.h"
#include "DFS.h"
int main(){
	int node,origin,dest,option,source;
	cout<<endl<<"Enter the number of nodes in the graph"<<endl;
	cin>>node;
	int max_edge;
	AdjacencyMatrix am(node);
	AdjacencyList al(node);
	BFS bfs;
	DFS dfs(al);
	do{
	cout<<endl<<"1.Enter the edges for adjacency matrix"<<endl;
	cout<<endl<<"2.Print Adjacency Matrix"<<endl;
	cout<<endl<<"3.Enter the edges for adjacency list for undirected graph"<<endl;
	cout<<endl<<"4.Enter the edges you want to delete for adjacency list for undirected graph"<<endl;
	cout<<endl<<"5.Print Adjacency List"<<endl;
	cout<<endl<<"6.Enter the edges for adjacency list for directed graph"<<endl;
	cout<<endl<<"7.Enter the edges you want to delete for adjacency list for directed graph"<<endl;
	cout<<endl<<"8.BFS of graph"<<endl;
	cout<<endl<<"9.DFS of graph"<<endl;

	cout<<endl<<"Enter -1 to exit"<<endl;
	cin>>option;
	switch(option){
	case 1:
		max_edge=node*(node-1);
		for(int i=0;i<max_edge;i++){
		cout<<"Enter the edges(press -1 -1 for exiting)(edge from 0 to node-1)";
		cin>>origin>>dest;
		if(origin==-1 || dest==-1){
			break;
		}
		am.addEdge(origin,dest);
		}
		break;
	case 2:

		am.printAdjacencyMatrix();
		break;
	case 3:
		max_edge=node*(node-1);
		for(int i=0;i<max_edge;i++){
		cout<<"Enter the edges(press -1 -1 for exiting)(edge from 0 to node-1) for undirected graph";
		cin>>origin>>dest;
		if(origin==-1 || dest==-1){
			break;
		}
		al.add_edge_undirected(origin,dest);
		}
		break;
	case 4:
		for(int i=0;i<max_edge;i++){
		cout<<"Enter the edges(press -1 -1 for exiting)(edge from 0 to node-1) that you want to delete for undirected graph";
		cin>>origin>>dest;
		if(origin==-1 || dest==-1){
			break;
		}
		al.del_edge_undirected(origin,dest);
		}
		break;
	case 5:
		al.printAdjList();
		break;
	case 6:
		max_edge=node*(node-1);
		for(int i=0;i<max_edge;i++){
		cout<<"Enter the edges(press -1 -1 for exiting)(edge from 0 to node-1) for directed graph";
		cin>>origin>>dest;
		if(origin==-1 || dest==-1){
			break;
		}
		al.add_edge_directed(origin,dest);
		}
		break;
	case 7:
		for(int i=0;i<max_edge;i++){
		cout<<"Enter the edges(press -1 -1 for exiting)(edge from 0 to node-1) that you want to delete for directed graph";
		cin>>origin>>dest;
		if(origin==-1 || dest==-1){
			break;
		}
		al.del_edge_directed(origin,dest);
		}
		break;
	case 8:
		cout<<endl<<"Enter the source node"<<endl;
		cin>>source;
		bfs.BFS_Graph(al,source);
		break;
	case 9:
		cout<<endl<<"Enter the source node"<<endl;
		cin>>source;
		dfs.DFS_Graph(al,source);
		break;
	}
	}while(option!=-1);
}
