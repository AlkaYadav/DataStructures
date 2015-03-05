#ifndef __BFS_H_INCLUDED__   // if x.h hasn't been included yet...
#define __BFS_H_INCLUDED__
#include<queue>
#include "AdjacencyList.h"
using namespace std;
class BFS{
public:
	void BFS_Graph(AdjacencyList al,int sourcenode);
	void printQueueContent(queue<int>);
};

#endif
