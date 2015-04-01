#include "FordFulkersonAlgorithm.h"
#include"MaximumBipartiteMatching.h"
int main(){
	int node,option,origin,dest,source,weight,sink;
	int jobs,applicants;
	cout<<endl<<"Enter the number of nodes in the graph"<<endl;
	cin>>node;
	int max_edge;
	AdjacencyMatrix am(node);
	MaximumBipartiteMatching mbp;
	FordFulkerson ff;
	do{
		cout<<endl<<"1.Enter the edges for adjacency matrix"<<endl;
		cout<<endl<<"2.Print Adjacency Matrix"<<endl;
		cout<<endl<<"3.Ford Fulkerson of graph"<<endl;
		cout<<endl<<"4. Maximum Bipartite Matching"<<endl;
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
				cout<<endl<<"Enter the source node and sink node"<<endl;
				cin>>source>>sink;
				cout<<"max flow is "<<ff.FordFulkersonAlgorithm(am,source,sink);
				break;
		case 4:
				cout<<endl<<"Enter the applicants and jobs for finding maximum bipartite matching"<<endl;
				cin>>applicants>>jobs;
				mbp.insertAdjacencyMatrix(applicants,jobs);
				cout<<"Maximum matching is "<<mbp.maximumBipartiteMatching();
				break;
		}
	}while(option!=-1);
	return 0;
}
