#include "Heap.h"

int main(){
	int size,option,index,newkey;
	cout<<"Enter the size of array"<<endl;
	cin>>size;
	Heap h(size);
	do{
		cout<<endl<<"1.MAX HEAP"<<endl;
		cout<<endl<<"2.MIN HEAP"<<endl;
		cout<<endl<<"3.HEAP SORT"<<endl;
		cout<<endl<<"4.EXTRACT MAX"<<endl;
		cout<<endl<<"5.INCREASE KEY"<<endl;
		cout<<endl<<"6.INSERT NEW VALUE"<<endl;
		cout<<endl<<"7.DECREASE KEY"<<endl;
		cout<<endl<<"8.PRINT HEAP"<<endl;
		cout<<endl<<"Enter -1 to exit"<<endl;
		cin>>option;
		switch(option){
		case 1:
			h.build_max_heap();
			h.printHeap();
			break;
		case 2:
			//h.buildMinHeap();
			break;
		case 3:
			h.heapSort();
			break;
		case 4:
			cout<<endl<<"Maximum is:::"<<h.extract_max()<<endl;
			break;
		case 5:
			cout<<endl<<"Enter the index starting from 0 to increase value of"<<endl;
			cin>>index;
			cout<<endl<<"Enter increased value"<<endl;
			cin>>newkey;
			h.increase_key(index,newkey);
			break;
		case 6:
			cout<<"Enter value to be inserted"<<endl;
			cin>>newkey;
			h.insert_key(newkey);
			break;
		case 7:
			cout<<endl<<"Enter the index starting from 0 to decrease value of"<<endl;
			cin>>index;
			cout<<endl<<"Enter decreased value"<<endl;
			cin>>newkey;
			h.decrease_key(index,newkey);
			break;
		case 8:
			h.printHeap();
			break;
		}
			}while(option!=-1);
	return 0;
		}

