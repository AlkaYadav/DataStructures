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
	bst.insert(25);
	bst.insert(20);
	bst.insert(46);
	bst.insert(47);
	bst.insert(48);

	//Insert random

	bst.insertRandomForSecondBST(50);
	bst.insertRandomForSecondBST(40);
	bst.insertRandomForSecondBST(60);
	bst.insertRandomForSecondBST(30);
	bst.insertRandomForSecondBST(45);
	bst.insertRandomForSecondBST(55);
	bst.insertRandomForSecondBST(70);
	bst.insertRandomForSecondBST(25);
	bst.insertRandomForSecondBST(20);
	bst.insertRandomForSecondBST(46);
	bst.insertRandomForSecondBST(47);
	bst.insertRandomForSecondBST(48);
	cout<<endl<<"Number of nodes in BST are:"<<bst.count()<<endl;
	bst.inorder();
	cout<<endl<<"Postorder"<<endl;
	bst.postorder();
	cout<<endl<<"Postorder Iterative"<<endl;
	bst.postorderIterative();
	bst.preorder();
	cout<<endl<<"Diameter of BST:"<<bst.diameter();
	cout<<endl<<"Minimum value in BST:"<<bst.minimum()<<endl;
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
	cout<<endl<<"Deleting BST:"<<endl;
	bst.deleteBST();
	cout<<endl<<"Number of nodes in BST are:"<<bst.count()<<endl;
}
