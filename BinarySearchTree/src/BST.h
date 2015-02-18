#include "Node.h"
#include<iostream>
using namespace std;
class BST{
private:
	Node *root;
	void insertHelper(Node **,int);
	int countHelper(Node *);
	void inorderHelper(Node *);
public:
	BST();
	void insert(int);
	int count();
	void inorder();
};
