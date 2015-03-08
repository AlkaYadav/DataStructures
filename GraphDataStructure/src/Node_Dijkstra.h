#ifndef __Node_Dijkstra_H_INCLUDED__   // if x.h hasn't been included yet...
#define __Node_Dijkstra_H_INCLUDED__   //   #define this so the compiler knows it has been included

class Node_Dijkstra{
	int data;
	int weight;
	Node_Dijkstra *next;
	friend class Graph_Dijkstra;
};

#endif
