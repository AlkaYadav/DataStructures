#ifndef __DFS_H_INCLUDED__   // if x.h hasn't been included yet...
#define __DFS_H_INCLUDED__   //   #define this so the compiler knows it has been included
#include "AdjacencyList.h"
class DFS{
	bool *visited;
public:
	DFS(AdjacencyList al);
	void DFS_Graph(AdjacencyList,int sourcenode);
};

#endif
