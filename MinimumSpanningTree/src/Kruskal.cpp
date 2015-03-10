#include "Kruskal.h"
static int count_edge=0;
Kruskal::Kruskal(int node,int edge){
	this->nodes=node;
	this->edges=edge;
	edge_kruskal=new Edge_Kruskal[edge];
}

//Insert an edge in graph
void Kruskal::add_edge(int src,int dest,int weight){
	(edge_kruskal+count_edge)->src=src;//TODO
	edge_kruskal[count_edge].dest=dest;
	edge_kruskal[count_edge].weight=weight;
	count_edge++;
}

//Prints the graph
void Kruskal::printGraph(){
	for(int i=0;i<edges;i++){
		cout<<""<<edge_kruskal[i].src<<"->"<<edge_kruskal[i].dest<<":::"<<edge_kruskal[i].weight<<endl;
	}
}
int Kruskal::cmpfunc(const void *a,const void *b){
	return (((Edge_Kruskal*)a)->weight) - (((Edge_Kruskal*)b)->weight);
}

//MST using kruskal
void Kruskal::KruskalMST(){
	 int count_edges_mst=0;
	 int i=0;
	 int *parent=new int [nodes];
	 Edge_Kruskal* result_mst=new Edge_Kruskal[nodes-1];
	 qsort(edge_kruskal,edges, sizeof(Edge_Kruskal),cmpfunc);
	 cout<<"Graph"<<endl;
	 printGraph();
	 for(int i=0;i<nodes;i++){
		 parent[i]=i;
	 }
	 while(count_edges_mst!=nodes-1){
		 // A union-find algorithm to detect cycle in a graph
		 if(find(edge_kruskal[i],parent)==0){ //vertices of Edges not in same parent set
			 union_edge(edge_kruskal[i],parent);
			 result_mst[count_edges_mst++]=edge_kruskal[i];
		 }
		 i++;
	 }
	 printKruskal(result_mst);
}

int Kruskal::find(Edge_Kruskal e,int *parent){
	if(parent[e.src]==parent[e.dest]){
		return 1;
	}
	return 0;
}

//Union sets of two vertices if they are in different sets
void Kruskal::union_edge(Edge_Kruskal e,int *parent){
	int src_parent=parent[e.src];
	int dest_parent=parent[e.dest];
	for(int i=0;i<nodes;i++){
		if(parent[i]==src_parent){
			parent[i]=dest_parent;
		}
	}
}

void Kruskal::printKruskal(Edge_Kruskal result[]){
	for(int i=0;i<nodes-1;i++){
		cout<<""<<result[i].src<<"->"<<result[i].dest<<"==="<<result[i].weight<<endl;
	}
}
