#include "BellmanFord.h"
static int count_edge=0;
BellmanFord::BellmanFord(int vertices,int edges){
	this->vertices=vertices;
	this->edge=edges;
	edge_array=new Edge_Bellman*[edge];
	for(int i=0;i<edge;i++){
		edge_array[i]=NULL;
	}
}
//Add an edge to graph
void BellmanFord::add_edge(int src,int dest,int weight){
	edge_array[count_edge]=new Edge_Bellman();
	edge_array[count_edge]->src=src;
	edge_array[count_edge]->dest=dest;
	edge_array[count_edge]->weight=weight;
	count_edge++;
}

void BellmanFord::BellmanFordAlgorithm(int source){
	int *distance=new int[vertices];
	int *parent=new int[vertices];
	for(int i=0;i<vertices;i++){
		distance[i]=INT_MAX;
		parent[i]=INT_MAX;
	}
	distance[source]=0;
	parent[source]=-1;
	for(int i=1;i<vertices;i++){
		for(int j=0;j<edge;j++){
			if(distance[edge_array[j]->dest] > distance[edge_array[j]->src] + edge_array[j]->weight){
				if(distance[edge_array[j]->src]!=INT_MAX){
				distance[edge_array[j]->dest] = distance[edge_array[j]->src] + edge_array[j]->weight;
				parent[edge_array[j]->dest]=edge_array[j]->src;
				}
			}
		}
	}
	if(checkNegativeCycle(distance)==false){
	printDistanceArray(distance);
	printParentArray(parent);
	for (int i=0;i<vertices;i++){
			cout<<endl<<"============================================"<<endl;
			cout<<source<<"->";
			printShortestPathForAllVertices(parent,i);
		}
	}
	else{
		cout<<"Negative cycle detected.Shortest Path is negative infinity"<<endl;
	}
}

bool BellmanFord::checkNegativeCycle(int distance[]){
	int i;
	for(i=1;i<=vertices;i++){
			for(int j=0;j<edge;j++){
				if(i==vertices){
					if(distance[edge_array[j]->dest] > distance[edge_array[j]->src] + edge_array[j]->weight){
							return true;
				}
				}
				else{
				if(distance[edge_array[j]->dest] > distance[edge_array[j]->src] + edge_array[j]->weight){
					if(distance[edge_array[j]->src]!=INT_MAX){
					distance[edge_array[j]->dest] = distance[edge_array[j]->src] + edge_array[j]->weight;
					}
				}
			}
		}
	}
			return false;
}

void BellmanFord::printDistanceArray(int dist[]){
	for(int i=0;i<vertices;i++){
		cout<<"Vertex"<<i<<"Distance:"<<dist[i]<<endl;
	}
}

void BellmanFord::printParentArray(int parent[]){
	for(int i=0;i<vertices;i++){
		cout<<"Vertex"<<i<<"Parent:"<<parent[i]<<endl;
	}
}

void BellmanFord::printGraph(){
	for(int i=0;i<edge;i++){
		cout<<edge_array[i]->src<<"->"<<edge_array[i]->dest<<"wt:"<<edge_array[i]->weight<<endl;
	}
}

void BellmanFord::printShortestPathForAllVertices(int *parent,int source){
	if(parent[source]!=-1){
		printShortestPathForAllVertices(parent,parent[source]);
		cout<<source<<"->";
	}
}
