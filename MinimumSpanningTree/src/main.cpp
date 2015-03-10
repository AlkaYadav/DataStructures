#include "Kruskal.h"
#include "Prim.h"
int main(){
	int node,edge,weight,origin,dest,option,max_edge;
		cout<<"Enter the number of nodes and edges"<<endl;
		cin>>node>>edge;
		AdjacencyList al(node);
		Prim p;
		Kruskal k(node,edge);
		do{
			cout<<endl<<"1.Enter the edges for Kruskal MST"<<endl;
			cout<<endl<<"2.Kruskal MST Algorithm"<<endl;
			cout<<endl<<"3.Print Graph"<<endl;
			cout<<endl<<"4.Enter the edges for adjacency list for undirected graph"<<endl;
			cout<<endl<<"5.Prim of graph"<<endl;
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
			case 4:
				max_edge=node*(node-1);
				for(int i=0;i<max_edge;i++){
				cout<<"Enter the edges(press -1 -1 for exiting)(edge from 0 to node-1) for undirected graph";
				cin>>origin>>dest>>weight;
				if(origin==-1 || dest==-1){
					break;
				}
				al.add_edge_undirected(origin,dest,weight);
				}
				break;
			case 5:
				p.PrimAlgorithm(al);
				break;
			}
		}while(option!=-1);
		return 0;
	}
