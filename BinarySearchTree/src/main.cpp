#include "BST.h"
int main(){
	BST bst;
	bst.insert(2);
	bst.insert(3);
	cout<<endl<<"Number of nodes in BST are:"<<bst.count()<<endl;
	bst.inorder();
}
