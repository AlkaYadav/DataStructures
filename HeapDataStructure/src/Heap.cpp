#include "Heap.h"
void swap(int *num1,int *num2);
Heap::Heap(int size_of_arr){
	this->size=10000;
	this->heapsize=size_of_arr;
	heap_arr=new int[size];
	for(int i=0;i<heapsize;i++){
		cin>>heap_arr[i];
	}
}

//Max heapify function
void Heap::max_heapify(int index,int tmp_size){
	int left=2*index+1;
	int right=2*index+2;
	int largest=index;
	if(left<tmp_size && heap_arr[left]>heap_arr[index]){
		largest=left;
	}
	if(right<tmp_size && heap_arr[right]>heap_arr[largest]){
			largest=right;
		}
	if(largest!=index){
		swap(&heap_arr[largest],&heap_arr[index]);
		max_heapify(largest,tmp_size);
	}

}

void swap(int *num1,int *num2){
	int *tmp=new int(0);
	*tmp=*num1;
	*num1=*num2;
	*num2=*tmp;
}

//Build max heap
void Heap::build_max_heap(){
	for(int i=((heapsize/2)-1);i>=0;i--){
		max_heapify(i,heapsize);
	}
}

//Heap sort
void Heap::heapSort(){
	build_max_heap();
	int tmp_size=heapsize;
	while(tmp_size){
		swap(&heap_arr[0],&heap_arr[tmp_size-1]);
		tmp_size--;
		max_heapify(0,tmp_size);
	}
	printHeap();
}

void Heap::printHeap(){
	cout<<endl<<"Elements are:::"<<endl;
	for(int i=0;i<heapsize;i++){
		cout<<heap_arr[i]<<" ";
	}
}

//Extract max and delete it
int Heap::extract_max(){
	build_max_heap();
	int max=heap_arr[0];
	swap(&heap_arr[0],&heap_arr[heapsize-1]);
	heapsize--;
	max_heapify(0,heapsize);
	return max;
}

//Increase value of key at an index
void Heap::increase_key(int index,int newkey){
	build_max_heap();
	if(heap_arr[index]>=newkey){
		return;
	}
	else{
		heap_arr[index]=newkey;
		while(index!=0 || heap_arr[index]>heap_arr[(index-1)/2]){
			swap(&heap_arr[index],&heap_arr[(index-1)/2]);
			index=(index-1)/2;
		}
	}
}

//Decrease value of a key at an index
void Heap::decrease_key(int index,int newkey){
	build_max_heap();
		if(heap_arr[index]<=newkey){
			return;
		}
		else{
			heap_arr[index]=newkey;
			max_heapify(index,heapsize);
		}
}
//Insert a new value in heap
void Heap::insert_key(int value){
	heapsize++;
	heap_arr[heapsize-1]=value;
	build_max_heap();
}
