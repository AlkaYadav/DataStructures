#include "Node.h"
#include<iostream>
using namespace std;
class BST{
private:
	Node *root;
	void insertHelper(Node **,int);
	int countHelper(Node *);
	int minimumHelper(Node *);
	bool searchHelper(Node *,int);
	void inorderHelper(Node *);
	void preorderHelper(Node *);
	void postorderHelper(Node *);

public:
	BST();
	void insert(int);
	int count();
	int minimum();
	bool search(int);
	void inorder();
	void preorder();
	void postorder();

};
