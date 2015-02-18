#include "BST.h"
int main(){
	BST bst;
	bst.insert(3);
	bst.insert(4);
	bst.insert(2);
	cout<<endl<<"Number of nodes in BST are:"<<bst.count()<<endl;
	bst.inorder();
	bst.postorder();
	bst.preorder();
}
