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
	this->heapsize=size;
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

//Calculates parent ,left and right of an index

int HuffmanMinHeap::parent(int index){
   return (index-1)/2;
}

//For index start with 0
int HuffmanMinHeap::left(int index){
	return 2*index+1;
}

//For index start with 0
int HuffmanMinHeap::right(int index){
	return 2*index+2;
}

//Is size of heap one
bool HuffmanMinHeap::isSizeOne(){
	return (heapsize==1);
}

//Check if given node is a leaf node
bool HuffmanMinHeap::isLeafNode(HuffmanNode *node){
	return (node->left==NULL) && (node->right==NULL);
}

//Swap two nodes
void HuffmanMinHeap::swap(int index1,int index2){
	HuffmanNode *tmpnode;
	tmpnode=heapnodearray[index1];
	heapnodearray[index1]=heapnodearray[index2];
	heapnodearray[index2]=tmpnode;
}
//Min Heapify
void HuffmanMinHeap::min_heapify(int index){
	int _left=left(index);
	int _right=right(index);
	int smallest=index;
//cout<<"In min heapify"<<endl;
    if(_left<heapsize && heapnodearray[_left]->count<heapnodearray[smallest]->count){
    	smallest=_left;
    }
    if(_right<heapsize && heapnodearray[_right]->count<heapnodearray[smallest]->count){
    	smallest=_right;
    }
    if(smallest!=index){
    	swap(smallest,index);
    	cout<<"After swap is done"<<endl;
    	cout<<"Printing ..."<<endl;
    	printHeap();
    	min_heapify(smallest);
    }
}

//Build Min Heap
void HuffmanMinHeap::build_min_heap(){
	cout<<"In build min heap"<<endl;
   for(int i=(heapsize/2)-1;i>=0;i--){
	   cout<<"For index"<<i<<"calling min heapify"<<endl;
	   min_heapify(i);
	   printHeap();
   }
   //To REmove
   cout<<"after min heap build done"<<endl;
   printHeap();
}

//Extract minimum element from min heap
HuffmanNode* HuffmanMinHeap::extractmin(){
	HuffmanNode *smallestNode;
	HuffmanNode *lastNode;
	smallestNode=heapnodearray[0];
	if(isSizeOne()){
		return smallestNode;
	}
	lastNode=heapnodearray[heapsize-1];
	swap(0,heapsize-1);
	heapsize--;
	min_heapify(0);
	return smallestNode;
}

//Decrease min heap key value
void HuffmanMinHeap::decreaseMinHeapKey(int index,int key){
	if(heapnodearray[index]->count<key){
		cout<<"Value must be less than"<<heapnodearray[index]->data;
		return;
	}
	heapnodearray[index]->data=key;
	int _parent =parent(index);
	while(index>0 && heapnodearray[index]->count<heapnodearray[_parent]->count){
		swap(index,_parent);
		index=_parent;
		_parent=parent(index);
	}
}

//Get a new node
HuffmanNode* HuffmanMinHeap::getNewNode(){
	HuffmanNode *newnode=new HuffmanNode();
	newnode->data='I';
	newnode->count=INT_MAX;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}

//Insert min heap node
HuffmanNode* HuffmanMinHeap::insertminheap(int count){
	HuffmanNode *newnode=getNewNode();
	heapsize++;
	heapnodearray[heapsize-1]=newnode;
	decreaseMinHeapKey(heapsize-1,count);
	return newnode;
}

//Print Min heap
void HuffmanMinHeap::printHeap(){
	for(int i=0;i<heapsize;i++){
		cout<<heapnodearray[i]->data<<"->"<<heapnodearray[i]->count<<endl;
	}
}
//Code starts for huffman code finally

HuffmanCoding::HuffmanCoding(char *characters,int * count,int size){
	hminheap=new HuffmanMinHeap(characters,count,size);
	cout<<"In huffman coding const"<<endl;
}

//Build huffman tree
void HuffmanCoding::buildHuffmanTree(){
	cout<<"In build huffman coding const"<<endl;
	hminheap->build_min_heap();
	hminheap->printHeap();
	while(!hminheap->isSizeOne()){
		HuffmanNode *minimum1=hminheap->extractmin();
		HuffmanNode *minimum2=hminheap->extractmin();
		cout<<"Extracting minimum 1"<<minimum1->count<<endl;
		cout<<"Extracting minimum 2"<<minimum2->count<<endl;
		HuffmanNode *newnode=hminheap->insertminheap(minimum1->count+minimum2->count);
		newnode->left=minimum1;
		newnode->right=minimum2;
	}
   //printHuffmanCodes(hminheap->heapnodearray[0]);
}


//Print Huffman code
void HuffmanCoding::printHuffmanCodes(HuffmanNode *node){
    if(hminheap->heapsize<=0)
    	return;
	while(!hminheap->isLeafNode(node)){
		if(node->left){
			cout<<"0";
			printHuffmanCodes(node->left);
		}
		if(node->right){
					cout<<"1";
					printHuffmanCodes(node->right);
	    }

	}
	cout<<node->data<<endl;


}
