//============================================================================
// Name        : HuffmanCoding.cpp
// Author      : alkayadav
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "HuffmanCoding.h"
#define MAX_TREE_SIZE 100

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
    	min_heapify(smallest);
    }
}

//Build Min Heap
void HuffmanMinHeap::build_min_heap(){
	cout<<"In build min heap"<<endl;
   for(int i=(heapsize/2)-1;i>=0;i--){
	   min_heapify(i);
   }
}

//Extract minimum element from min heap
HuffmanNode* HuffmanMinHeap::extractmin(){
	HuffmanNode *smallestNode;
	HuffmanNode *lastNode;
	smallestNode=heapnodearray[0];
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
	heapnodearray[index]->count=key;
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
	while(!hminheap->isSizeOne()){
		HuffmanNode *minimum1=hminheap->extractmin();
		HuffmanNode *minimum2=hminheap->extractmin();
		HuffmanNode *newnode=hminheap->insertminheap(minimum1->count+minimum2->count);
		newnode->left=minimum1;
		newnode->right=minimum2;
	}
	int arr[MAX_TREE_SIZE];
	HuffmanNode *minimum1=hminheap->extractmin();
	int top = 0;
    printHuffmanCodes(minimum1,arr,top);
}


//Print Huffman code
void HuffmanCoding::printHuffmanCodes(HuffmanNode *node,int arr[],int top){

	if(node->left){
		arr[top]=0;
		printHuffmanCodes(node->left,arr,top+1);
	}
	if(node->right){
			arr[top]=1;
			printHuffmanCodes(node->right,arr,top+1);
	}
	if(hminheap->isLeafNode(node)){
		cout<<"Code for"<<node->data<<"::";
		for(int i=0;i<top;i++){
							cout<<arr[i];
		}
	}
	cout<<endl;

}
