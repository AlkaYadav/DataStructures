#include "BST.h"
int main(){
	BST bst;
	int node1,node2;
	int data,sum;
	char ans='y',ins='y';
	int option;
	do{
	cout<<endl<<"Menu:"<<endl;
	cout<<endl<<"1. Insert data in BST"<<endl;
	cout<<endl<<"2. Count number of nodes in BST"<<endl;
	cout<<endl<<"3. Catalan number of BST"<<endl;
	cout<<endl<<"4. Inorder traversal of BST"<<endl;
	cout<<endl<<"5. Preorder traversal of BST"<<endl;
	cout<<endl<<"6. Postorder traversal of BST"<<endl;
	cout<<endl<<"7. Postorder Iterative"<<endl;
	cout<<endl<<"8. hasPathSum in BST"<<endl;
	cout<<endl<<"9. Diameter of BST"<<endl;
	cout<<endl<<"10. Minimum value in BST"<<endl;
	cout<<endl<<"11. Search node in BST"<<endl;
	cout<<endl<<"12. Parent of a node in BST"<<endl;
	cout<<endl<<"13. Tree successor of a node in BST"<<endl;
	cout<<endl<<"14. Depth of BST"<<endl;
	cout<<endl<<"15. Check if tree is BST"<<endl;
	cout<<endl<<"16. Find lowest common ancestors of two nodes in BST"<<endl;
	cout<<endl<<"17. Check for similarity of two BSTs"<<endl;
	cout<<endl<<"18. Print all possible paths in BST"<<endl;
	cout<<endl<<"19. Delete node in BST"<<endl;
	cout<<endl<<"20. Delete all nodes in BST"<<endl;
	cin>>option;
	switch(option){
					case 1:
						do{
							cout<<endl<<"Enter the data"<<endl;
							cin>>data;
							bst.insert(data);
							cout<<endl<<"Do you want to enter more data"<<endl;
							cin>>ins;
						}while(ins=='y'||ins=='Y');
						break;
					case 2:
						cout<<endl<<"Number of nodes in BST are:"<<bst.count()<<endl;
						break;
					case 3:
						cout<<endl<<"Number of binary trees possible with count"<<bst.count()<<" is :"<<bst.catalanNumber(bst.count())<<endl;
						break;
					case 4:
						cout<<endl<<"Inorder"<<endl;
						bst.inorder();
						break;
					case 5:
						cout<<endl<<"Preorder"<<endl;
						bst.preorder();
						break;
					case 6:
						cout<<endl<<"Postorder"<<endl;
						bst.postorder();
						break;
					case 7:
						cout<<endl<<"Postorder Iterative"<<endl;
						bst.postorderIterative();
						break;
					case 8:
						cout<<endl<<"Enter the sum to check in BST"<<endl;
						cin>>sum;
						cout<<endl<<"Result:"<<bst.hasPathSum(sum)<<endl;
						break;
					case 9:
						cout<<endl<<"Diameter of BST:"<<bst.diameter();
						break;
					case 10:
						cout<<endl<<"Minimum value in BST:"<<bst.minimum()<<endl;
						break;
					case 11:
						cout<<endl<<"Enter the element you want to search:"<<endl;
						cin>>data;
						cout<<bst.search(data);
						break;
					case 12:
						cout<<endl<<"Enter the node data to find parent of:"<<endl;
						cin>>data;
						cout<<endl<<"Parent is:"<<endl<<bst.parentNode(data)<<endl;
						break;
					case 13:
						cout<<"Enter node to find Tree successor for:"<<endl;
						cin>>data;
						cout<<bst.treeSuccessor(data);
						break;
					case 14:
						cout<<endl<<"Maximum depth of BST:"<<bst.depth()<<endl;
						break;
					case 15:
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
						cout<<endl<<"isBST:"<<bst.isBST()<<endl;
						break;
					case 16:
						cout<<endl<<"Enter the nodes for finding lowest common ancestor"<<endl;
						cin>>node1>>node2;
						cout<<endl<<"Lowest common ancestor of "<<node1<<"and"<<node2<<"is:"<<bst.lowestCommonAncestor(node1,node2);
						break;
					case 17:
						cout<<"Checking for similarity of two BSTs:"<<endl;
						cout<<endl<<"Result of checking similarity:"<<bst.checkTreesSimilarity()<<endl;
						break;
					case 18:
						bst.printAllPossiblePaths();
						break;
					case 19:
						cout<<endl<<"Enter the node you want to delete"<<endl;
						cin>>data;
						bst.deleteBSTNode(data);
						cout<<endl<<"Now the tree is"<<endl;
						bst.inorder();
						break;
					case 20:
						cout<<endl<<"Deleting BST:"<<endl;
						bst.deleteBST();
						cout<<endl<<"Number of nodes in BST are:"<<bst.count()<<endl;
						break;
					}
	cout<<endl<<"Press y to continue"<<endl;
	cin>>ans;
			}while(ans=='y'||ans=='Y');
return 0;
}
