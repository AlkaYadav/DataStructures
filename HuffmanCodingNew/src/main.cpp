#include "HuffmanCoding.h"

int main(){
	int vertices,destination,source,response;

	char *characters;
	int *count;
	int size;
	int option;
	cout<<"Enter number of entries for huffman code"<<endl;
	cin>>size;
	characters=new char[size];
	count=new int[size];
	for(int i=0;i<size;i++){
		cout<<"Enter character"<<i<<"and its frequency"<<endl;
		cin>>characters[i]>>count[i];
		cout<<endl;
	}
	HuffmanCoding h(characters,count,size);
	do{
			cout<<endl<<"Menu:"<<endl;
			cout<<endl<<"1. Print huffman code"<<endl;
			cout<<endl<<"-1. Enter -1 to quit"<<endl;
			cin>>option;
					switch(option){
									case 1:
										h.buildHuffmanTree();
										break;
					             }
		}while(option !=-1);
}
