#include "BST.h"
int main(){
	BST bst;
	int data;
	bst.insert(3);
	bst.insert(4);
	bst.insert(2);
	cout<<endl<<"Number of nodes in BST are:"<<bst.count()<<endl;
	bst.inorder();
	bst.postorder();
	bst.preorder();
	cout<<endl<<"Minimum value in BST:"<<bst.minimum();
	cout<<endl<<"Enter the element you want to search:"<<endl;
	cin>>data;
	bst.search(data);
}
