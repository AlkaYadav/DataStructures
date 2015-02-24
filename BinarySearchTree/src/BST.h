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
	Node * searchHelper(Node *,int);
	int depthHelper(Node *);
	int diameterHelper(Node *);
	bool isBSTHelper(Node *);

	Node *parentNodeHelper(Node *,int data);
	int treeSuccessorHelper(Node *);

	bool hasPathSumHelper(Node*,int );
	void inorderHelper(Node *);
	void preorderHelper(Node *);
	void postorderHelper(Node *);
	void postorderIterativeHelper(Node *);
	void printAllPossiblePathsHelper(Node*,int paths[],int len);
	void printPath(int paths[],int len);
	bool checkTreesSimilarityHelper(Node *,Node *);
	Node * deleteBSTNodeHelper(Node *,int);
	Node * find_min(Node *);
	void deleteBSTHelper(Node **);

public:
	BST();
	void insert(int);
	int count();
	int catalanNumber(int n);
	int minimum();
	Node * search(int);
	int depth();
	int diameter();
	bool isBST();
    int parentNode(int data);
	int treeSuccessor(int data);
	int lowestCommonAncestor(int node1,int node2);
	bool hasPathSum(int sum);

	void inorder();
	void preorder();
	void postorder();
	void postorderIterative();

	void printAllPossiblePaths();
	bool checkTreesSimilarity();
	void insertRandomForSecondBST(int);
	void deleteBSTNode(int data);
	void deleteBST();

};
