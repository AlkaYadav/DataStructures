#include"EulerPath.h"

Graph::Graph(int nodes){
	this->nodes=nodes;
	adj=new list<int>[nodes];
}

void Graph::addEdge(int node1,int node2){
	adj[node2].push_back(node1);
	adj[node1].push_back(node2);
}
void Graph::rmEdge(int source,int dest){
	list<int>::iterator i=find(adj[source].begin(),adj[source].end(),dest);
	*i=-1;
	list<int>::iterator j=find(adj[dest].begin(),adj[dest].end(),source);
	*j=-1;
}

void Graph::printGraph(){
	list<int>::iterator iter;
	for(int i=0;i<nodes;i++){
		cout<<endl<<"For node "<<i<<endl;
		for(iter=adj[i].begin();iter!=adj[i].end();iter++){
			cout<<*iter<<" ";
		}
		cout<<endl;
	}
}
bool EulerPath::isEulerian(Graph g){
	int count=0;
	if(!isConnected(g)){
		return false;
	}
	for(int i=0;i<g.nodes;i++){
		if(g.adj[i].size()%2!=0){
			count++;
		}
	}
	if(count==0){
		cout<<endl<<"Graph has Euler circuit"<<endl;
		return true;
	}
	else if(count==2){
		cout<<endl<<"Graph has Euler path not euler circuit"<<endl;
		return true;
	}
	return false;
}

bool EulerPath::isConnected(Graph g){
	int *visited=new int[g.nodes];
	int source,i;
	for(int i=0;i<g.nodes;i++){
		visited[i]=0;
	}
	list<int>::iterator iter;
	for( i=0;i<g.nodes;i++){
		if(g.adj[i].size()>0){
			source=i;
			break;
		}
	}
	if(i==g.nodes){
		cout<<endl<<"Graph consists of isolated vertices only"<<endl;
		return true;
	}
	DFSCount(g,source,visited);
	for(int i=0;i<g.nodes;i++){
		if(visited[i]==0&&g.adj[i].size()>0){
			return false;
		}
	}
	return true;
}
int EulerPath::DFSCount(Graph g,int src,int *visited){
	int count=1;
	visited[src]=1;
	list<int>::iterator i;
	for(i=g.adj[src].begin();i!=g.adj[src].end();i++){
		if(*i!=-1 && visited[*i]==0){
			visited[*i]=1;
			count+=DFSCount(g,*i,visited);
		}
	}
	return count;
}

void EulerPath::printEulerPathOrCircuit(Graph g){
	if(isEulerian(g)){
		int source,i,count=0;
		for( i=0;i<g.nodes;i++){
			//it works for euler path
			if(g.adj[i].size()>0 && g.adj[i].size()%2!=0){
				source=i;
				count++;
				break;
			}
		}
		if(count==0){
			for( i=0;i<g.nodes;i++){
						//it works for euler path
						if(g.adj[i].size()>0){
							source=i;
							break;
						}
		}
		}

		if(i==g.nodes){
			cout<<"Graph is isolated so Eulerian also.But no path to be printed as there are no edges"<<endl;
			return;
		}
		else{
		printEulerPathOrCircuitUtil(g,source);
		}
	}
}
void EulerPath::printEulerPathOrCircuitUtil(Graph g,int source){
	list<int>::iterator iter;
	for(iter=g.adj[source].begin();iter!=g.adj[source].end();iter++){
		int node=*iter;
		if(*iter!=-1 && isValidNextEdge(g,source,node)){
			cout<<source<<"->"<<node<<endl;
			g.rmEdge(source,node);
			printEulerPathOrCircuitUtil(g,node);
		}
	}
}

bool EulerPath::isValidNextEdge(Graph g,int source,int dest){
	list<int>::iterator iter;
	int count1,count2;
	int *visited=new int[g.nodes];
	for(int i=0;i<g.nodes;i++){
		visited[i]=0;
	}
	int count=0;
	for(iter=g.adj[source].begin();iter!=g.adj[source].end();iter++){
			if(*iter!=-1){
				count++;
			}
	}
	if(count==1){
		return true;
	}
	else{
		count1=DFSCount(g,source,visited);
		g.rmEdge(source,dest);
		for(int i=0;i<g.nodes;i++){
				visited[i]=0;
			}
		count2=DFSCount(g,source,visited);
		g.addEdge(source,dest);
	}
	return count1>count2? false:true;
}
