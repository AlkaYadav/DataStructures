#include "Node.h"
#include<iostream>
using namespace std;
class BST{
private:
	Node *root;
	Node *root2;   //Second BST
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
	bool checkTreesSimilarityHelper(Node *,Node *);

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
	bool checkTreesSimilarity();
	void insertRandomForSecondBST(int);
};
