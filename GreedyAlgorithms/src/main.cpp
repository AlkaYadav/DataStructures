/*
 * main.cpp
 *
 *  Created on: Jun 23, 2015
 *      Author: alkyadav
 */
#include "Graph.h"
#include "UnionFind.h"
#include "KruskalMST.h"

int main(){


	int vertices,destination,source,response;
	int vertex_edgelist,edges;
	cout<<endl<<"Enter the number of vertices"<<endl;
	cin>>vertices;
	Graph g(vertices);
	cout<<endl<<"Enter the number of vertices for edgelist graph"<<endl;
	cin>>vertex_edgelist;
	cout<<endl<<"Enter the number of edges for edgelist graph"<<endl;
	cin>>edges;
	Graph_EdgeList ge(vertex_edgelist,edges);
	UnionFind uf;
	KruskalMST kmst;
	int option;
		do{
		cout<<endl<<"Menu:"<<endl;
		cout<<endl<<"1. Insert edge in Graph"<<endl;
		cout<<endl<<"2. Print Graph"<<endl;
		cout<<endl<<"3. Insert edge in EdgeListGraph"<<endl;
		cout<<endl<<"4. Print EdgeListGraph"<<endl;
		cout<<endl<<"5. Union Find algorithm to detect cycle in EdgeListGraph"<<endl;
		cout<<endl<<"6. Union Find algorithm to detect cycle in EdgeListGraph(Union by rank and PathCompression)"<<endl;
		cout<<endl<<"7.Print Kruskal MST"<<endl;
		cout<<endl<<"-1. Enter -1 to quit"<<endl;
		cin>>option;
		switch(option){
						case 1:

								do{
									cout<<"Enter source"<<endl;
									cin>>source;
									cout<<"Enter destination"<<endl;
									cin>>destination;

									g.insertEdge_undirected(source,destination);
									cout<<"Enter -1 to stop inserting more edges"<<endl;
									cin>>response;
								}while(response!=-1);
							break;
						case 2:
							cout<<"Graph is:"<<endl;
							g.printGraph();
							break;
						case 3:
							ge.addEdges();
							break;
						case 4:
							ge.printGraph();
							break;
						case 5:
							uf.isCycle(ge);
							break;
						case 6:
							uf.isCycle_UnionByRankPathCompression(ge);
							break;
						case 7:
							kmst.printKruskalMST(ge);
							break;

		             }
          }while(option !=-1);
}



