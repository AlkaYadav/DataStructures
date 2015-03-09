#include "Graph_Dijkstra.h"

Graph_Dijkstra::Graph_Dijkstra(int nodes){
	this->node=nodes;
	adjList=new Node_Dijkstra*[node];
	for(int i=0;i<node;i++){
		adjList[i]=NULL;
	}
}

//Add weighted directed edge
void Graph_Dijkstra::add_edge_directed_Djikstra(int origin,int dest,int wt){
	if(adjList[origin]==NULL){
			Node_Dijkstra* node=new Node_Dijkstra();
			node->data=dest;
			node->next=NULL;
			node->weight=wt;
			adjList[origin]=node;
		}
		else{//TODO:Not yet checking for duplicate entries
			Node_Dijkstra* node=new Node_Dijkstra();
			node->data=dest;
			node->next=adjList[origin];
			node->weight=wt;
			adjList[origin]=node;
		}
}

//Find Djikstra_Algorithm of graph
void Graph_Dijkstra::Djikstra_Algorithm(int sourcenode){
	int distance[node];
	int parent[node];
	bool final_list[node];//set containing nodes whose shortest distance is calculated
	distance[sourcenode]=0;
	parent[sourcenode]=-1;

	for(int i=0;i<node;i++){
		if(i!=sourcenode){
			distance[i]=INT_MAX;
			parent[i]=-1;
			final_list[i]=false;
		}
	}
	while(length(final_list)!=node){
		int node_with_min_distance=findMin(distance,final_list);//Find the node with minimum distance from source,that node is in complement of final_list
		final_list[node_with_min_distance]=true;
		Node_Dijkstra *tmp=adjList[node_with_min_distance];
		while(tmp){
			int new_dist=distance[node_with_min_distance]+(tmp->weight);
			if(new_dist<distance[tmp->data]){
				distance[tmp->data]=new_dist;
				parent[tmp->data]=node_with_min_distance;
			}
			tmp=tmp->next;
		}
	}

	for (int i=0;i<node;i++){
		cout<<endl<<"============================================"<<endl;
		cout<<sourcenode<<"->";
		printShortestPath(parent,i);
	}

}

//Find number of nodes whose shortest distance is calculated
int Graph_Dijkstra::length(bool *a){
	int count=0;
	for(int i=0;i<node;i++){
		if(a[i]==true){
			count++;
		}
	}
	return count;
}
//Find the minimum from complement set to be removed and inserted to final set
int Graph_Dijkstra::findMin(int distance[],bool final_list[]){
	int mindist=INT_MAX;
	int index;
	for(int i=0;i<node;i++){
		if(final_list[i]==false){
			if(distance[i]<mindist){
				mindist=distance[i];
				index=i;
			}
		}
	}
	return index;
}
//Print shortest paths from source to all nodes
void Graph_Dijkstra::printShortestPath(int parent[],int sourcenode){
	if(parent[sourcenode]!=-1){
		printShortestPath(parent,parent[sourcenode]);
		cout<<sourcenode<<"->";
	}
}
