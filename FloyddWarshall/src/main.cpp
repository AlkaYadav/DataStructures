#include "FloyddWarshall.h"
int main(){
	int node,origin,dest,option,weight;
	cout<<endl<<"Enter the number of nodes in the graph"<<endl;
	cin>>node;
	int max_edge;
	AdjacencyMatrix am(node);
	Floydd fl;
	do{
		cout<<endl<<"1.Enter the edges for adjacency matrix"<<endl;
		cout<<endl<<"2.Print Adjacency Matrix"<<endl;
		cout<<endl<<"3.FloyddWarshall of graph"<<endl;
			cout<<endl<<"Enter -1 to exit"<<endl;
			cin>>option;
			switch(option){
			case 1:
				max_edge=node*(node-1);
				for(int i=0;i<max_edge;i++){
				cout<<"Enter the edges(press -1 -1 for exiting)(edge from 0 to node-1)";
				cin>>origin>>dest>>weight;
				if(origin==-1 || dest==-1){
					break;
				}
				am.addEdge(origin,dest,weight);
				}
				break;
			case 2:
				am.printAdjacencyMatrix();
				break;
			case 3:
				fl.FloyddWarshallAlgorithm(am);
				break;
            }
	}while(option!=-1);
}
