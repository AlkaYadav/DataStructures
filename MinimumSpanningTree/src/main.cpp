#include "Kruskal.h"
int main(){
	int node,edge,weight,origin,dest,option;
		cout<<"Enter the number of nodes and edges"<<endl;
		cin>>node>>edge;
		Kruskal k(node,edge);
		do{
			cout<<endl<<"1.Enter the edges for Kruskal MST"<<endl;
			cout<<endl<<"2.Kruskal MST Algorithm"<<endl;
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
				k.add_edge(origin,dest,weight);
				}
				break;
			case 2:
				k.KruskalMST();
				break;
			case 3:
				k.printGraph();
				break;
			}
		}while(option!=-1);
		return 0;
	}
