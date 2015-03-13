#include "Heap.h"

int main(){
	int size,option;
	cout<<"Enter the size of array"<<endl;
	cin>>size;
	Heap h(size);
	do{
		cout<<endl<<"1.Enter the elements for making heap"<<endl;
		cout<<endl<<"2.MAX HEAP"<<endl;
		cout<<endl<<"3.MIN HEAP"<<endl;
		cout<<endl<<"4.HEAP SORT"<<endl;
		cout<<endl<<"Enter -1 to exit"<<endl;
		cin>>option;
		switch(option){
		case 1:
			h.input_array();

			break;
		case 2:
			h.buildMaxHeap();
			break;
		case 3:
			h.buildMinHeap();
			break;
		case 4:
			h.heapSort();
			break;
		}
			}while(option!=-1);
	return 0;
		}

