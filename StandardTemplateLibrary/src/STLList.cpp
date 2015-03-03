#include"STLList.h"


void STLList::printElements(list<int> L){
	list<int>::iterator it;
	cout<<endl;
	for(it=L.begin();it!=L.end();it++){
		cout<<*it<<"->";
	}
	cout<<endl;
}
void STLList::pushElements(){
	list<int> L;
	L.push_back(4);
	L.push_front(3);
	L.insert(++L.begin(),13);
	L.insert(++L.begin(),2,19);
	printElements(L);
}

void STLList::deleteElement(){
	list<int> L;
	list<int>::iterator it1,it2;
	for(int i=1;i<10;i++){
		L.push_back(i*10);
	}
	it2=it1=L.begin();
	advance(it2,6);
	++it1;
	printElements(L);
	it1=L.erase(it1);
	it2=L.erase(it2);
	++it1;
	--it2;
	L.erase(it1,it2);
	printElements(L);
}
