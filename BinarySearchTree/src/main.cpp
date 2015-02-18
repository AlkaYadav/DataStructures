#include "BST.h"
int main(){
	BST bst;
	int data;
	bst.insert(50);
	bst.insert(40);
	bst.insert(60);
	bst.insert(30);
	bst.insert(45);
	bst.insert(55);
	bst.insert(70);

	//Insert random

	bst.insertRandomForSecondBST(50);
	bst.insertRandomForSecondBST(40);
	bst.insertRandomForSecondBST(60);
	bst.insertRandomForSecondBST(30);
	bst.insertRandomForSecondBST(45);
	bst.insertRandomForSecondBST(53);
	bst.insertRandomForSecondBST(70);
	cout<<endl<<"Number of nodes in BST are:"<<bst.count()<<endl;
	bst.inorder();
	bst.postorder();
	bst.preorder();
	cout<<endl<<"Minimum value in BST:"<<bst.minimum();
	cout<<endl<<"Enter the element you want to search:"<<endl;
	cin>>data;
	cout<<endl<<"Result of search:"<<bst.search(data)<<endl;
	cout<<endl<<"Maximum depth of BST:"<<bst.depth()<<endl;
	cout<<endl<<"isBST:"<<bst.isBST()<<endl;
	bst.inorder();
	bst.postorder();
	bst.preorder();
	cout<<"Checking for similarity of two BSTs:"<<endl;
	cout<<endl<<"Result of checking similarity:"<<bst.checkTreesSimilarity()<<endl;
	bst.printAllPossiblePaths();
}
