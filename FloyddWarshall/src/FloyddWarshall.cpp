#include "FloyddWarshall.h"

AdjacencyMatrix::AdjacencyMatrix(int nodes){
	node=nodes;
	adj = new int*[node];  //Dynamic memory allocation
	for(int i=0;i<node;i++){
		adj[i]=new int[node];    //Dynamic memory allocation
			for(int j=0;j<node;j++){
				adj[i][j]=INT_MAX;
			}
	}

}

void AdjacencyMatrix::addEdge(int origin,int dest,int weight){
	if(origin>=node||origin<0||dest>=node||dest<0){
		cout<<endl<<"Invalid entry"<<endl;
		return;
	}
	else{
		adj[origin][dest]=weight;
	}
}

void AdjacencyMatrix::printAdjacencyMatrix(){
	for(int i=0;i<node;i++){
		cout<<endl;
		for(int j=0;j<node;j++){
			cout<<adj[i][j]<<" ";
		}
		cout<<endl;
	}
}

void Floydd::FloyddWarshallAlgorithm(AdjacencyMatrix am){
	for(int i=0;i<am.node;i++){
		for(int j=0;j<am.node;j++){
			for(int k=0;k<am.node;k++){
				if(i==j||am.adj[i][k]==INT_MAX || am.adj[k][j]==INT_MAX){

				}
				else
				if(am.adj[i][j]>(am.adj[i][k]+am.adj[k][j])){
					am.adj[i][j]=am.adj[i][k]+am.adj[k][j];
				}
			}
		}
	}

	cout<<endl<<"All Pair Shortest Path Result:"<<endl;
	for(int i=0;i<am.node;i++){
			for(int j=0;j<am.node;j++){
				if(i==j){
					cout<<"-  ";
				}
				else if(am.adj[i][j]==INT_MAX){
					cout<<"INF";
				}
				else{
				cout<<am.adj[i][j]<<"  ";
				}
			}
			cout<<endl;
			}
}
