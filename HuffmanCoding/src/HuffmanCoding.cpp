//============================================================================
// Name        : HuffmanCoding.cpp
// Author      : alkayadav
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "HuffmanCoding.h"

HuffmanMinHeap::HuffmanMinHeap(char *characters,int * count,int size){
	this->size=size;
	//Creating heap with the input character array and count array
	heapnodearray=new HuffmanNode*[size];
	for(int i=0;i<size;i++){
		heapnodearray[i]=new HuffmanNode();
		heapnodearray[i]->data=characters[i];
		heapnodearray[i]->count=count[i];
		heapnodearray[i]->left=NULL;
		heapnodearray[i]->right=NULL;
	}
}
void HuffmanMinHeap::min_heapify(int index){
	int left=2*index+1;
	int right=2*index;
	int largest=index;
    if(left<heapsize && heapnodearray[left]->data>heapnodearray[index]->data){
    	largest=left;
    }
    if(left<heapsize && heapnodearray[right]->data>heapnodearray[index]->data){
        	largest=right;
    }
    if(largest!=index){
    	swap(heapnodearray,largest,index);
    	min_heapify(largest);
    }
}
