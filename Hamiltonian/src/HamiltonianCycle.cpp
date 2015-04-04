#include"HamiltonianCycle.h"

Graph::Graph(int nodes){
	this->nodes=nodes;
	adj = new int*[nodes];  //Dynamic memory allocation
	for(int i=0;i<nodes;i++){
		adj[i]=new int[nodes];    //Dynamic memory allocation
			for(int j=0;j<nodes;j++){
				adj[i][j]=0;
			}
	}

}

void Graph::addEdge(int origin,int dest){
	if(origin>=nodes||origin<0||dest>=nodes||dest<0){
		cout<<endl<<"Invalid entry"<<endl;
		return;
	}
	else{
		adj[origin][dest]=1;
		adj[dest][origin]=1;
	}
}

void Graph::printGraph(){
	for(int i=0;i<nodes;i++){
		cout<<endl;
		for(int j=0;j<nodes;j++){
			cout<<adj[i][j]<<" ";
		}
		cout<<endl;
	}
}


void HamiltonianCycle::printHamiltonianPath(Graph g,int* path){
	cout<<"Hamiltonian cycle"<<endl;
	for(int i=0;i<=g.nodes;i++){
		cout<<path[i]<<"->";
	}
}

bool HamiltonianCycle::isSafe(int node,int pos,Graph g,int *path){
	if(g.adj[path[pos-1]][node]==0){
		return false;
	}
	for(int i=0;i<g.nodes;i++){
		if(path[i]==node){
			return false;
		}
	}
	return true;
}
bool HamiltonianCycle::hamiltonianCycle(Graph g,int *path,int pos){
	if(pos==g.nodes){
		if(g.adj[path[pos-1]][path[0]]==1){
			path[pos]=path[0];
			return true;
		}
		else{
			return false;
		}
	}
	else{
		for(int i=1;i<g.nodes;i++){
			if(isSafe(i,pos,g,path)){
				path[pos]=i;
				if(hamiltonianCycle(g,path,pos+1)==true)
					return true;
				path[pos]=-1;
			}
		}

	}
	return false;
}
bool HamiltonianCycle::HamiltonianCycle::isHamiltonian(Graph g){
	int *path=new int[g.nodes+1];
	int pos;
	for(int i=0;i<g.nodes+1;i++){
		path[i]=-1;
	}
	path[0]=0;
	pos=1;
	if(hamiltonianCycle(g,path,pos)){
		printHamiltonianPath(g,path);
		return true;
	}
	else{
		cout<<"No Hamiltonian cycle exists"<<endl;
		return false;
	}
}

