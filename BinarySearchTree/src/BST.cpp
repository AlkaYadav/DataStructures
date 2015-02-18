#include"BST.h"
#include<stdio.h>

//Constructor
BST::BST(){
	root = NULL;
}

//Insert Function in BST
void BST::insert(int data){
	insertHelper(&root,data);
}
void BST::insertHelper(Node **node,int data){
	if(*node == NULL){
		*node = new Node();
		(*node)-> data = data;
		(*node) -> left = NULL;
		(*node) ->right = NULL;
		cout<<endl<<"Inserted data"<<data<<endl;
	}
	else if(data<(*node)->data){
		insertHelper(&(*node)->left,data);
	}
	else {
			insertHelper(&(*node)->right,data);
		}
}

//Count nodes in a BST
int BST::count(){
	return countHelper(root);
}

int BST::countHelper(Node *node){
	if(node == NULL){
		return 0;
	}
	else return 1+countHelper(node->left)+countHelper(node->right);
}

//Find the minimum value of BST
int BST::minimum(){
	if(root == NULL){
		cout<<endl<<"BST empty.So no minimum"<<endl;
		return -1;
	}
	else{
		return minimumHelper(root);
	}
}

int BST::minimumHelper(Node *node){
	if(node->left == NULL){
		return node->data;
	}
	else{
		return minimumHelper(node->left);
	}
}

//Search element in BST
bool BST::search(int data){
	if(root == NULL){
			cout<<endl<<"BST empty.So no element to search."<<endl;
			return -1;
		}
		else{
			return searchHelper(root,data);
		}
}

bool BST::searchHelper(Node *node,int data){
	if(node == NULL){
		return false;
	}
	if(data == node->data){
		cout<<endl<<"Found:"<<node->data;
		return true;
	}
	else if(data < node->data){
		return searchHelper(node->left,data);
	}
	else if(data > node->data){
		return searchHelper(node->right,data);
	}
	else{
		cout<<endl<<"Not Found:"<<data<<endl;
		return false;
	}
}

//Find the maximum depth of BST
int BST::depth(){
	if(root == NULL){
		cout<<endl<<"BST with no elements"<<endl;
		return 0;
	}
	else return depthHelper(root);
}

int BST::depthHelper(Node *node){
	if(node == NULL){
		return 0;
	}
	else return 1+max(depthHelper(node->left),depthHelper(node->right));

}
//Find the diameter of BST
int BST::diameter(){
	if(root == NULL){
		return 0;
	}
	else{
		return diameterHelper(root);
	}
}

int BST::diameterHelper(Node *node){
	if(node == NULL){
		return 0;
	}
	else{
		int lheight = depthHelper(node->left);
		int rheight = depthHelper(node->right);
		int ldiameter = diameterHelper(node->left);
		int rdiameter = diameterHelper(node->right);
		return max(max(1+lheight+rheight,ldiameter),rdiameter);

	}
}
//Check if a given tree is a BST
bool BST::isBST(){
	if(root == NULL){
		cout<<endl<<"Empty tree"<<endl;
		return true;
	}
	else{
		return isBSTHelper(root);
	}
}

bool BST::isBSTHelper(Node *node){
	if(node->left == NULL && node-> right == NULL){
		return true;
	}
	else if(node->left && node-> right){
		if(node->left->data < node->data && node->right->data > node->data){
			return isBSTHelper(node->left) && isBSTHelper(node->right);
		}
	}
	else if(node->left && (node-> right)){
		if(node->left->data < node->data){
			return isBSTHelper(node->left);
		}
		else {
			return false;
		}
	}
	else if(!(node->left) && node-> right){
		if(node->right->data > node->data){
					return isBSTHelper(node->right);
				}
				else {
					return false;
				}
	}
	return true;
}

//Inorder Traversal of BST
void BST::inorder(){
	if(root == NULL){
		cout<<"BST empty";
	}
	else{
		cout<<endl<<"Inorder Traversal"<<endl;
		inorderHelper(root);
	}
}

void BST::inorderHelper(Node *node){
	if(node == NULL){
		return;
	}
	else{
		inorderHelper(node -> left);
		cout<<node->data<<"->";
		inorderHelper(node -> right);
	}
}

//Preorder Traversal of BST
void BST::preorder(){
	if(root == NULL){
		cout<<"BST empty";
	}
	else{
		cout<<endl<<"Preorder Traversal"<<endl;
		preorderHelper(root);
	}
}

void BST::preorderHelper(Node *node){
	if(node == NULL){
		return;
	}
	else{
		cout<<node->data<<"->";
		preorderHelper(node -> left);
		preorderHelper(node -> right);
	}
}

//Postorder Traversal of BST
void BST::postorder(){
	if(root == NULL){
		cout<<"BST empty";
	}
	else{
		cout<<endl<<"Postorder Traversal"<<endl;
		postorderHelper(root);
	}
}

void BST::postorderHelper(Node *node){
	if(node == NULL){
		return;
	}
	else{
		postorderHelper(node -> left);
		postorderHelper(node -> right);
		cout<<node->data<<"->";
	}
}
//Print all possible paths in a BST
void BST::printAllPossiblePaths(){
	if(root == NULL){
		cout<<endl<<"Tree empty.No possible paths exist"<<endl;
	}
	else{
		int paths[20];
		printAllPossiblePathsHelper(root,paths,0);
	}
}

void BST::printAllPossiblePathsHelper(Node* node,int paths[],int len){
	paths[len++] = node->data;
	if(node->left == NULL && node->right == NULL){
		printPath(paths,len);
	}
	else{
		printAllPossiblePathsHelper(node->left,paths,len);
		printAllPossiblePathsHelper(node->right,paths,len);
	}

}

void BST::printPath(int paths[],int len){
	cout<<endl;
	cout<<"Possible path:"<<endl;
	for(int i=0;i<len;i++){
		cout<<paths[i]<<"->";
	}
	cout<<endl;
}

//Check if two binary trees are same or not

bool BST::checkTreesSimilarity(){
	if(root == NULL && root2 == NULL){
		return true;
	}
	else{
		return checkTreesSimilarityHelper(root,root2);
	}

}

bool BST::checkTreesSimilarityHelper(Node *node1,Node *node2){
	if(node1 == NULL && node2 == NULL){
		return true;
	}
	else if(node1->data == node2->data){
		return checkTreesSimilarityHelper(node1->left,node2->left) &&
				checkTreesSimilarityHelper(node1->right,node2->right);
	}
	else return false;
}

//Insert random for second BST
void BST::insertRandomForSecondBST(int data){
	insertHelper(&root2,data);
}
