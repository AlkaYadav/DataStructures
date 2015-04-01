#include "FordFulkersonAlgorithm.h"

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

void AdjacencyMatrix::printpath(int *parent, int src, int dest)
{
	if(parent[dest]==-1)
	{
		return;
	}
	else
	{
		printpath(parent, src, parent[dest]);
		cout<<dest<<"-->";

	}
}
//Find if there is a path from src to sink with weight>0
bool AdjacencyMatrix::BFS(int src, int sink, int *parent, int residual[][V]){
	queue<int> q;
	int num;
	int *visited=new int[node];
	for(int i=0;i<node;i++){
		visited[i]=0;
	}
	visited[src]=1;
	q.push(src);
	parent[src]=-1;
	while(!q.empty()){
		num=q.front();
		q.pop();
		for(int i=0;i<node;i++){
			if(residual[num][i]>0 && visited[i]==0){
				visited[i]=1;
				parent[i]=num;
				q.push(i);
			}
		}
	}
return (visited[sink]==1);
}

//Flow network from source to sink
int FordFulkerson::FordFulkersonAlgorithm(AdjacencyMatrix am,int src,int sink){
	int min_flow=INT_MAX;
	int max_flow=0;
	int *parent=new int[am.node];
	int *visited=new int[am.node];
	int residual[V][V];
	for(int i=0;i<am.node;i++){
		parent[i]=-1;
		for(int j=0;j<am.node;j++){
			residual[i][j]=am.adj[i][j];
		}
	}

	while(am.BFS(src,sink,parent,residual)){
		for(int i=sink;i!=src;i=parent[i]){
			if(residual[parent[i]][i]<min_flow){
				min_flow=residual[parent[i]][i];
			}
		}
		for(int i=sink;i!=src;i=parent[i]){
			residual[parent[i]][i]-=min_flow;
			residual[i][parent[i]]+=min_flow;
		}
		max_flow+=min_flow;
	}
	for(int i=0;i<am.node;i++){
		visited[i]=0;
	}
	dfs(am,residual,src,visited);
	cout<<endl<<"Minimum cut edges"<<endl;
	for(int i=0;i<am.node;i++){
		for(int j=0;j<am.node;j++){
			if(visited[i] && !visited[j] &&am.adj[i][j]){
				cout<<endl<<i<<"->"<<j<<endl;
			}
		}
	}
return max_flow;
}

void FordFulkerson::dfs(AdjacencyMatrix am,int residual[][V],int src,int *visited){
	visited[src]=1;
	for(int i=0;i<am.node;i++){
		if(residual[src][i] && visited[i]==0){
			visited[i]=1;
			dfs(am,residual,i,visited);
		}
	}
}
