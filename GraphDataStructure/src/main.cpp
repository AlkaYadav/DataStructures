#include"AdjacencyMatrix.h"
int main(){
	int node,origin,dest,option;
	cout<<endl<<"Enter the number of nodes in the graph"<<endl;
	cin>>node;
	AdjacencyMatrix am(node);
	do{
	cout<<endl<<"1.Enter the edges"<<endl;
	cout<<endl<<"2.Print Adjacency Matrix"<<endl;
	cout<<endl<<"Enter -1 to exit"<<endl;
	cin>>option;
	switch(option){
	case 1:
		int max_edge=node*(node-1);
		for(int i=0;i<max_edge;i++){
		cout<<"Enter the edges(press -1 -1 for exiting)";
		cin>>origin>>dest;
		if(origin!=-1 || dest!=-1){
			break;
		}
		am.addEdge(origin,dest);
		}

		break;
	case 2:
		am.printAdjacencyMatrix();
	}
	}while(option!=-1);
}
