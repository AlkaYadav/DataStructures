#include "Heap.h"

Heap::Heap(int size){
	a=new int[size];
	this->size=size;
	for(int i=0;i<size;i++){
		a[i]=0;
	}
}
void Heap::input_array(){
	cout<<endl<<"Enter the elements::"<<endl;
	for(int i=0;i<size;i++){
		cin>>a[i];
	}
}

//Max heapify function
void Heap::max_Heapify(int max_size,int index){
	int left=2*index+1;
	int right=2*index+2;
	int largest=index;
	if(left<max_size && a[largest]<a[left]){
		largest=left;
	}
	if(right<max_size && a[largest]<a[right]){
		largest=right;
	}
	if(largest!=index){
		cout<<endl<<"Swapped are:"<<a[largest]<<"and"<<a[index]<<endl;
		int tmp=a[largest];
		a[largest]=a[index];
		a[index]=tmp;
		max_Heapify(max_size,largest);
	}
}

//Min heapify
void Heap::min_Heapify(int max_size,int index){
	int left=2*index+1;
	int right=2*index+2;
	int least=index;
	if(left<max_size && a[least]>a[left]){
		least=left;
	}
	if(right<max_size && a[least]>a[right]){
		least=right;
	}
	if(least!=index){
		int tmp=a[least];
		a[least]=a[index];
		a[index]=tmp;
		max_Heapify(max_size,least);
	}
}

//Build min heap
void Heap::buildMinHeap(){
	for(int i=(size-1)/2;i>=0;i--){
		min_Heapify(size,i);
	}
	printHeap();
}
void Heap::buildMaxHeap(){
	for(int i=(size-1)/2;i>=0;i--){
		max_Heapify(size,i);
	}
	printHeap();
}

//Heap sort
void Heap::heapSort(){
	int max_size=size;
	int tmp;
	buildMaxHeap();
	for(int i=max_size-1;i>0;i--){
		tmp=a[i];
		a[i]=a[0];
		a[0]=tmp;
		max_size--;
		max_Heapify(max_size,0);
	}
	printHeap();
}

//Print heap
void Heap::printHeap(){
	cout<<endl<<"Heap::"<<endl;
	for(int i=0;i<size;i++){
		cout<<a[i]<<" ";
	}
}
