#include"STLVector.h"

void STLVector::insertVecElements(){
	vector<int> myVec;
	for(int i=0;i<10;i++){
	myVec.push_back(i+1);
    }
	myVec.insert(myVec.begin(),33);
	printVeclements(myVec);
	cout<<endl<<"Printing for a particular position"<<myVec.at(3)<<endl;;
}

void STLVector::deleteVecElement(vector<int> myVec){
	vector<int>::iterator vt1,vt2;
	vt2=vt1=myVec.begin();
	myVec.erase(vt1);
	vt2++;
	myVec.erase(vt1,vt2);
	myVec.clear();  //Delete all elements
}
void STLVector::printVeclements(vector<int> myVec){
	if(myVec.empty()){
		cout<<"Empty vector"<<endl;
	}
	else{
		vector<int>::iterator v1;
		cout<<endl<<"Vector size"<<myVec.size()<<endl;
		cout<<endl;
		for(v1=myVec.begin();v1!=myVec.end();v1++){
			cout<<*v1<<"->";
		}
		cout<<endl;
	}
}
