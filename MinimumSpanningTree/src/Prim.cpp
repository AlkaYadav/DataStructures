#include "Prim.h"

AdjacencyList::AdjacencyList(int nodes){
	this->node=nodes;
	adjList=new Node*[node];
	for(int i=0;i<node;i++){
		adjList[i]=NULL;
	}
}

void AdjacencyList::add_edge_undirected(int origin,int dest,int weight){
	add_edge_directed(origin,dest,weight);
	add_edge_directed(dest,origin,weight);
}

void AdjacencyList::add_edge_directed(int origin,int dest,int weight){
	if(adjList[origin]==NULL){
		Node* node=new Node();
		node->data=dest;
		node->weight=weight;
		node->next=NULL;
		adjList[origin]=node;
	}
	else{//TODO:Not yet checking for duplicate entries
		Node* node=new Node();
		node->data=dest;
		node->next=adjList[origin];
		node->weight=weight;
		adjList[origin]=node;
	}
}

void Prim::PrimAlgorithm(AdjacencyList al){
	int count_nodes_mst=0;
	int *distance=new int[al.node];
	int *result=new int[al.node];
	bool *final_list=new bool[al.node];
	for(int i=0;i<al.node;i++){
		distance[i]=INT_MAX;
		final_list[i]=false;
	}
	distance[0]=0;
	while(count_nodes_mst!=al.node){
		int index_min_dist=findMin(al,distance,final_list);
		final_list[index_min_dist]=true;
		result[count_nodes_mst]=index_min_dist;
		Node *tmp=al.adjList[index_min_dist];
		while(tmp){
			if(distance[tmp->data]>(tmp->weight)){
				distance[tmp->data]=(tmp->weight);
			}
			tmp=tmp->next;
		}
		count_nodes_mst++;
	}
	cout<<"Nodes are inserted in the final list in order:"<<endl;
	for(int i=0;i<al.node;i++){
		cout<<result[i]<<endl;
	}
}

int Prim::findMin(AdjacencyList al,int distance[],bool final_list[]){
	int mindist=INT_MAX;
	int index;
	for(int i=0;i<al.node;i++){
		if(final_list[i]==false){
			if(distance[i]<mindist){
				mindist=distance[i];
				index=i;
			}
		}
	}
	return index;
}
