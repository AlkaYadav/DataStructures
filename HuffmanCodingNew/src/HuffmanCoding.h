/*
 * HuffmanCoding.h
 *
 *  Created on: Jun 28, 2015
 *      Author: alkyadav
 */

#ifndef HUFFMANCODING_H_
#define HUFFMANCODING_H_

#include <iostream>
#include<stdio.h>
#include<limits.h>
using namespace std;

class HuffmanNode{
	char data;
	int count;
	HuffmanNode *left;
	HuffmanNode *right;
	friend class HuffmanMinHeap;
	friend class HuffmanCoding;
};

class HuffmanMinHeap{
	int heapsize; //No. of elements in heap
	int size; //Total elements in array
	HuffmanNode ** heapnodearray;

	int parent(int index);
	int left(int index);
	int right(int right);
	void swap(int index1,int index2);
	HuffmanNode *getNewNode();
	bool isSizeOne();
	bool isLeafNode(HuffmanNode *node);
public:
	HuffmanMinHeap(char *characters,int * count,int size);
	void min_heapify(int index);
	void build_min_heap();
	HuffmanNode* extractmin();
	HuffmanNode* insertminheap(int count);
	void decreaseMinHeapKey(int index,int key);
	void printHeap();
	friend class HuffmanCoding;
};

class HuffmanCoding{
	//Declare below as pointer to object in order to
	//initialize HuffmanMinHeap object constructor
	HuffmanMinHeap *hminheap;
public:
	HuffmanCoding(char *characters,int * count,int size);
    void buildHuffmanTree();
    void printHuffmanCodes(HuffmanNode *root);
};
#endif /* HUFFMANCODING_H_ */
