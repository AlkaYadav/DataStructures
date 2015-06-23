#include "Graph.h"

Graph::Graph(int numberOfNodes){
	this->numberOfNodes = numberOfNodes;
	vertices = new Node*[numberOfNodes];
	for(int i=0;i<numberOfNodes;i++){
		vertices[i] = NULL;
	}
}

void Graph::insertEdge_undirected(int source, int destination){
	if(source<0 || source>numberOfNodes-1 || destination<0 || destination>numberOfNodes-1){
		cout<<"Invalid source or destination.Insert in range 0 to "<<numberOfNodes-1<<endl;
		return;
	}
	insertEdge_directedHelper(source, destination);
	insertEdge_directedHelper(destination, source);
}

void Graph::insertEdge_directedHelper(int source, int destination){
	//Case 1:Check if source list is empty
	if(!vertices[source]){
		//Allocate a new node
		Node *newnode=new Node();
		newnode->data=destination;
		newnode->next=NULL;
		vertices[source]=newnode;
	}
	else{
		Node *tmp=vertices[source];
		Node *prev=tmp;
		while(tmp){
		  prev=tmp;
          if(tmp->data==destination){
        	  cout<<"Failed to insert duplicate edge from :"<<source<<"to"<<destination<<endl;
        	  return;
          }
          tmp=tmp->next;
		}
		//Allocate a new node
		Node *newnode=new Node();
		newnode->data=destination;
		newnode->next=NULL;
	    prev->next=newnode;
	}
}
void Graph::printGraph(){
	Node *tmp;
	for(int i=0;i<numberOfNodes;i++){
		tmp=vertices[i];
		while(tmp){
			cout<<i<<"->"<<tmp->data<<endl;
			tmp=tmp->next;
		}
	}
}
