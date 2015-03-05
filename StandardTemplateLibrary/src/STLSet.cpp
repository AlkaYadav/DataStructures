#include"STLSet.h"

void STLSet::printElements(set<int> s){
	set<int>::iterator st1;
	cout<<endl;
	for(st1=s.begin();st1!=s.end();st1++){
		cout<<*st1<<"->";
	}
	cout<<endl;
}
void STLSet::insertSetElements(){
	set<int> mySet;
	set<int>::iterator st1;
	pair<set<int> ,bool> ret; //Declare a pair for insertion
	for(int i=1;i<10;i++){
		mySet.insert(i*2);
	}
	ret=mySet.insert(4);
	if(ret.second==true){
		st1=ret.first;
	}
	int myInts[]={15,87,67,1,76};
	mySet.insert(myInts,myInts+3);
	printElements(mySet);
}
void STLSet::deleteSetElement(){
	set<int> mySet;
	set<int>::iterator st1;
	for(int i=1;i<10;i++){
			mySet.insert(i*2);
		}
	mySet.erase(mySet.begin());
	st1=mySet.find(40);
	mySet.erase(st1);
}
