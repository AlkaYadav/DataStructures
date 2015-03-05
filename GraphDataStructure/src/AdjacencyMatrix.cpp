#include"AdjacencyMatrix.h"

AdjacencyMatrix::AdjacencyMatrix(int nodes){
	node=nodes;
	adj = new int*[node];  //Dynamic memory allocation
	for(int i=0;i<node;i++){
		adj[i]=new int[node];    //Dynamic memory allocation
			for(int j=0;j<node;j++){
				adj[i][j]=0;
			}
	}

}

void AdjacencyMatrix::addEdge(int origin,int dest){
	if(origin>=node||origin<0||dest>=node||dest<0){
		cout<<endl<<"Invalid entry"<<endl;
		return;
	}
	else{
		adj[origin][dest]=1;
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
