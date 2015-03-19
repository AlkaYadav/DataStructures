#ifndef __DFS_H_INCLUDED__   // if x.h hasn't been included yet...
#define __DFS_H_INCLUDED__   //   #define this so the compiler knows it has been included
#include "AdjacencyList.h"
class DFS{
	int time_v;
	char *color;
	int *parent;
	int *discovery;
	int *finish;
public:
	void DFS_Graph(AdjacencyList);
	void DFS_Visit(AdjacencyList al,int sourcenode);

};

#endif
