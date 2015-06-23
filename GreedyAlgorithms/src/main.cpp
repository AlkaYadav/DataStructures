/*
 * main.cpp
 *
 *  Created on: Jun 23, 2015
 *      Author: alkyadav
 */
#include "Graph.h"

int main(){


	int vertices,destination,source,response;
	cout<<endl<<"Enter the number of vertices"<<endl;
	cin>>vertices;
	Graph *g=new Graph(vertices);

	int option;
		do{
		cout<<endl<<"Menu:"<<endl;
		cout<<endl<<"1. Insert edge in Graph"<<endl;
		cout<<endl<<"2. Print Graph"<<endl;
		cout<<endl<<"-1. Enter -1 to quit"<<endl;
		cin>>option;
		switch(option){
						case 1:

								do{
									cout<<"Enter source"<<endl;
									cin>>source;
									cout<<"Enter destination"<<endl;
									cin>>destination;
									g->insertEdge_undirected(source,destination);
									cout<<"Enter -1 to quit"<<endl;
									cin>>response;
								}while(response!=-1);
							break;
						case 2:
							cout<<"Graph is:"<<endl;
							g->printGraph();
							break;
		             }
          }while(option !=-1);
}



