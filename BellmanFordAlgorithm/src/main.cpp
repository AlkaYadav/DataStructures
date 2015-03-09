#include"BellmanFord.h"
int main(){
	int node,edge,weight,origin,dest,option,source;
	cout<<"Enter the number of nodes and edges"<<endl;
	cin>>node>>edge;
	BellmanFord bf(node,edge);
	do{
		cout<<endl<<"1.Enter the edges for Bellman Ford"<<endl;
		cout<<endl<<"2.BellmanFord Algorithm"<<endl;
		cout<<endl<<"3.Print Graph"<<endl;
		cout<<endl<<"Enter -1 to exit"<<endl;
		cin>>option;
		switch(option){
		case 1:
			for(int i=0;i<edge;i++){
			cout<<"Enter the edges(press -1 -1 for exiting)(edge from 0 to node-1) and weight";
			cin>>origin>>dest>>weight;
			if(origin==-1 || dest==-1){
				break;
			}
			bf.add_edge(origin,dest,weight);
			}
			break;
		case 2:
			cout<<"Enter the source node"<<endl;
			cin>>source;
			bf.BellmanFordAlgorithm(source);
			break;
		case 3:
			bf.printGraph();
			break;
		}
	}while(option!=-1);
	return 0;
}
