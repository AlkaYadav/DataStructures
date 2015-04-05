#include"HamiltonianCycle.h"
int main(){
	int node,option,max_edge,origin,dest;
	HamiltonianCycle hc;
	cout<<endl<<"Enter the number of nodes in the graph"<<endl;
	cin>>node;
	Graph g(node);
	do{
		cout<<endl<<"1.Enter the edges for adjacency matrix"<<endl;
		cout<<endl<<"2.Find if Hamiltonian Cycle exists"<<endl;
		cout<<endl<<"3.Print graph"<<endl;
		cout<<endl<<"Enter -1 to exit"<<endl;
			cin>>option;
			switch(option){
			case 1:
				max_edge=node*(node-1);
				for(int i=0;i<max_edge;i++){
				cout<<"Enter the edges(press -1 -1 for exiting)(edge from 0 to node-1)";
				cin>>origin>>dest;
				if(origin==-1 || dest==-1){
					break;
				}
				g.addEdge(origin,dest);
				}
				break;
			case 2:
				cout<<endl<<"Hamiltonian Cycle:"<<endl;
				hc.isHamiltonian(g);
				break;
			case 3:
				g.printGraph();
				break;
			}
				}while(option!=-1);
}

