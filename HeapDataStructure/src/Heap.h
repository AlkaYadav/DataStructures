#ifndef __Heap_H_INCLUDED__   // if x.h hasn't been included yet...
#define __Heap_H_INCLUDED__   //   #define this so the compiler knows it has been included
#include<iostream>
using namespace std;
class Heap{
	int *a;
	int size;
	void printHeap();
public:
	Heap(int);
	void input_array();
	void max_Heapify(int max_size,int index);
	void min_Heapify(int max_size,int index);
	void buildMaxHeap();
	void buildMinHeap();
	void heapSort();

};
#endif
