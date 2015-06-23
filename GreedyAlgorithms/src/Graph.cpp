#include "Graph.h"

Graph::Graph(int numberOfNodes){
	cout<<"Entry";
	this->numberOfNodes = numberOfNodes;
	cout<<"Alka----";
	vertices = new Node*[numberOfNodes];
	cout<<"Alka";
	for(int i=0;i<numberOfNodes;i++){
		vertices[i]->next = NULL;
	}
}

void Graph::insertEdge_undirected(int source, int destination){
	insertEdge_directedHelper(source, destination);
	insertEdge_directedHelper(destination, source);
}
void Graph::insertEdge_directedHelper(int source, int destination){
	Node *newnode = new Node();
	Node * tmp = vertices[source]->next;
    while(tmp){
    	//Don't insert duplicate edge
    	if(tmp->data==destination){
    		return;
    	}
    	tmp = tmp->next;
    }
    tmp->next = newnode;
    newnode->data = destination;
    newnode->next = NULL;
}

void Graph::printGraph(){
	int index=0;
	Node *tmp;
	for(int i=0;i<numberOfNodes;i++){
		tmp=vertices[i]->next;
		while(tmp){
			cout<<vertices[i]<<"->"<<tmp<<endl;
			tmp=tmp->next;
		}
	}
}
