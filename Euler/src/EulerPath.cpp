#include"EulerPath.h"

Graph::Graph(int nodes){
	this->nodes=nodes;
	adj=new list<int>[nodes];
}

void Graph::addEdge(int node1,int node2){
	adj[node1].push_back(node1);
	adj[node2].push_back(node2);
}

bool EulerPath::isEulerian(Graph g){
	if(!isConnected(g)){
		return false;
	}
	for(int i=0;i<g.nodes;i++){
		if(g.adj[i].size()%2!=0){
			return false;
		}
	}
	return true;
}

bool EulerPath::isConnected(Graph g){
	int *visited=new int[g.nodes];
	for(int i=0;i<g.nodes;i++){
		visited[i]=0;
	}
	for(int i=0;i<g.nodes;i++){
		if(g.adj[i].size()==0){
			return false;
		}
	}
	g.DFS(0,visited);
	for(int i=0;i<g.nodes;i++){
		if(visited[i]==0&&g.adj[i].size()>0){
			return false;
		}
	}
	return true;
}
void Graph::DFS(int src,int *visited){
	visited[src]=1;
	list<int>::iterator i;
	for(i=adj[src].begin();i!=adj[src].end();i++){
		if(visited[*i]==0){
			visited[*i]=1;
			DFS(*i,visited);
		}
	}
}

bool EulerPath::hasEulerPath(Graph g){
	int count=0;
	if(!isConnected(g)){
			return false;
		}
	for(int i=0;i<g.nodes;i++){
		if(g.adj[i].size()%2!=0){
			count++;
		}
	}
	if(count==2){
		return true;
	}
	return false;
}

void printEulerPathOrCircuit(Graph){

}
