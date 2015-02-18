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
	int depthHelper(Node *);
	bool isBSTHelper(Node *);
	void inorderHelper(Node *);
	void preorderHelper(Node *);
	void postorderHelper(Node *);
	void printAllPossiblePathsHelper(Node*,int paths[],int len);
	void printPath(int paths[],int len);

public:
	BST();
	void insert(int);
	int count();
	int minimum();
	bool search(int);
	int depth();
	bool isBST();
	void inorder();
	void preorder();
	void postorder();
	void printAllPossiblePaths();
};
