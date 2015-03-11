#include "GraphColoring.h"

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
		adj[dest][origin]=1;
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
//Find if the graph can be colored with given m colors
void GraphColoring::GraphColoringAlgorithm(AdjacencyMatrix am,int m){
	int *color,cnt=-1;
	int *count=new int[m];
	color=new int[am.node];
	for(int i=0;i<am.node;i++){
		color[i]=-1;
	}
	for(int i=0;i<am.node;i++){
		for(int j=0;j<m;j++){
			if(test_for_color_validity(am,color,i,j,m)==true){
				color[i]=j;
				count[color[i]]++;
				break;
			}
		}
	}
for(int i=0;i<am.node;i++){
	if(count[i]>=0){
		cnt++;
	}
}
	if(cnt==m){
		for(int i=0;i<am.node;i++){
			cout<<endl<<"Node:"<<i<<" Color:"<<color[i]<<endl;
		}
	}
	else{
		cout<<endl<<"Invalid colors"<<endl;
		for(int i=0;i<am.node;i++){
					cout<<endl<<"Node:"<<i<<" Color:"<<color[i]<<endl;
				}
	}
}

bool GraphColoring::test_for_color_validity(AdjacencyMatrix am,int *color,int vertex,int color_type,int m){
	for(int k=0;k<am.node;k++){
		if(am.adj[vertex][k]==1){
			if(color[k]==color_type){
				return false;
			}
		}
	}
	return true;
}
