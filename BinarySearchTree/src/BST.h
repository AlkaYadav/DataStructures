#include "Node.h"
#include<iostream>
#include<stack>
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
	int diameterHelper(Node *);
	bool isBSTHelper(Node *);
	bool hasPathSumHelper(Node*,int );
	void inorderHelper(Node *);
	void preorderHelper(Node *);
	void postorderHelper(Node *);
	void postorderIterativeHelper(Node *);
	void printAllPossiblePathsHelper(Node*,int paths[],int len);
	void printPath(int paths[],int len);
	bool checkTreesSimilarityHelper(Node *,Node *);
	void deleteBSTHelper(Node **);

public:
	BST();
	void insert(int);
	int count();
	int minimum();
	bool search(int);
	int depth();
	int diameter();
	bool isBST();
	bool hasPathSum(int sum);
	void inorder();
	void preorder();
	void postorder();
	void postorderIterative();
	void printAllPossiblePaths();
	bool checkTreesSimilarity();
	void insertRandomForSecondBST(int);
	void deleteBST();
};
