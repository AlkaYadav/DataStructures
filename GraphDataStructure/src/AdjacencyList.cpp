#include"AdjacencyList.h"

AdjacencyList::AdjacencyList(int nodes){
	this->node=nodes;
	adjList=new Node*[node];
	for(int i=0;i<node;i++){
		adjList[i]=NULL;
	}
}

void AdjacencyList::add_edge_undirected(int origin,int dest){
	add_edge_directed(origin,dest);
	add_edge_directed(dest,origin);
}

void AdjacencyList::add_edge_directed(int origin,int dest){
	if(adjList[origin]==NULL){
		Node* node=new Node();
		node->data=dest;
		node->next=NULL;
		adjList[origin]=node;
	}
	else{//TODO:Not yet checking for duplicate entries
		Node* node=new Node();
		node->data=dest;
		node->next=adjList[origin];
		adjList[origin]=node;
	}
}
void AdjacencyList::del_edge_directed(int origin,int dest){
	if(adjList[origin]==NULL){
		cout<<"No such edge exists."<<endl;
		return;
	}
	else{
		Node *prev=NULL;
		Node *temp=adjList[origin];
		while(temp->data!=dest){
			prev=temp;
			temp=temp->next;
			if(temp==NULL){
				cout<<"Data not found"<<endl;
				return;
			}
		}
		if(prev==NULL){
			adjList[origin]=NULL;
			temp->next=NULL;
			delete temp;
		}
		else{
		prev->next=temp->next;
		temp->next=NULL;
		delete temp;
		}
	}
}

void AdjacencyList::del_edge_undirected(int origin,int dest){
	del_edge_directed(origin,dest);
	del_edge_directed(dest,origin);
}

void AdjacencyList::printAdjList(){
	for(int i=0;i<node;i++){
		cout<<i<<"::: ";
		Node *tmp=adjList[i];
		while(tmp){
			cout<<tmp->data<<"->";
			tmp=tmp->next;
		}
		cout<<endl;
	}
}
