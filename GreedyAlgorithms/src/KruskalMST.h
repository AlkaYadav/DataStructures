/*
 * KruskalMST.h
 *
 *  Created on: Jun 23, 2015
 *      Author: alkyadav
 */

#ifndef KRUSKALMST_H_
#define KRUSKALMST_H_
#include "UnionFind.h"

class KruskalMST{
	//It has to be a static method
	static int myComp(const void *a,const void *b);
public:
	void printKruskalMST(Graph_EdgeList ge);

};



#endif /* KRUSKALMST_H_ */
