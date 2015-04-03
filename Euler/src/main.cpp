#include"EulerPath.h"
int main(){
	int node,option,max_edge,origin,dest;
	EulerPath ep;
	cout<<endl<<"Enter the number of nodes in the graph"<<endl;
	cin>>node;
	Graph g(node);
	do{
		cout<<endl<<"1.Enter the edges for adjacency matrix"<<endl;
		cout<<endl<<"2.Find if Eulerian cycle exists"<<endl;
		cout<<endl<<"3.Find if Eulerian path exists"<<endl;
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
				if(ep.isEulerian(g)){
					cout<<endl<<"Graph has Eulerian cycle"<<endl;
				}
				else{
					cout<<endl<<"Graph doesn't have Eulerian cycle"<<endl;
				}
				break;
			case 3:
				if(ep.hasEulerPath(g)){
					cout<<endl<<"Graph has Eulerian path"<<endl;
				}
				else{
					cout<<endl<<"Graph doesn't have Eulerian path"<<endl;
				}
				break;
			}
				}while(option!=-1);
}

