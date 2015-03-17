#ifndef __Heap_H_INCLUDED__   // if x.h hasn't been included yet...
#define __Heap_H_INCLUDED__   //   #define this so the compiler knows it has been included
#include<iostream>
using namespace std;

class Heap{
	private:
		int *heap_arr;
		int heapsize;
		int size;

	public:
		Heap(int);
		void max_heapify(int index,int tmp_size);
		void build_max_heap();
		void heapSort();
		void printHeap();
		int extract_max();
		void increase_key(int index,int newkey);
		void insert_key(int value);
};
#endif
