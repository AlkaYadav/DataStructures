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
