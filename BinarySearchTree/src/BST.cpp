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
