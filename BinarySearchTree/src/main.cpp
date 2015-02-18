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
	cout<<endl<<"Result of search:"<<bst.search(data)<<endl;
	cout<<endl<<"Maximum depth of BST:"<<bst.depth()<<endl;
	cout<<endl<<"isBST:"<<bst.isBST()<<endl;
	bst.inorder();
}
