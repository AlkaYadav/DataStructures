/*
 * HuffmanCoding.h
 *
 *  Created on: Jun 28, 2015
 *      Author: alkyadav
 */

#ifndef HUFFMANCODING_H_
#define HUFFMANCODING_H_

#include <iostream>
using namespace std;

class HuffmanNode{
	char data;
	int count;
	HuffmanNode *left;
	HuffmanNode *right;
	friend class HuffmanMinHeap;
};

class HuffmanMinHeap{
	int heapsize; //No. of elements in heap
	int size; //Total elements in array
	HuffmanNode ** heapnodearray;
public:
	HuffmanMinHeap(char *characters,int * count,int size);
	void min_heapify(int index);
	void build_min_heap();
	HuffmanNode* extractmin();
	void insertminheap();
    void swap(HuffmanNode** heapnodearray,int largest,int index);
};

#endif /* HUFFMANCODING_H_ */
