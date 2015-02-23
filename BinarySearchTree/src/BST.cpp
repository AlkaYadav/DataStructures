#include"BST.h"
#include<stdio.h>
int globalInorder[20];
int globalPostorder[20];
int globalLenInorder=0;
int globalLenPostorder=0;
//Constructor
BST::BST(){
	root = NULL;
	root2 = NULL;
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
//Count number of binary trees for given n distinct elements.
int BST::catalanNumber(int n){
	int sum=0;
	if(n==0 || n==1){
		return 1;
	}
	else{
		for(int k=1;k<=n;k++){
			sum+=catalanNumber(k-1)*catalanNumber(n-k);
		}
	}
	return sum;
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
Node * BST::search(int data){
	if(root == NULL){
			cout<<endl<<"BST empty.So no element to search."<<endl;
			return NULL;
		}
		else{
			if(searchHelper(root,data))
			return searchHelper(root,data);
			else
				return NULL;
		}
}

Node * BST::searchHelper(Node *node,int data){
	if(node == NULL){
		return NULL;
	}
	if(data == node->data){
		return node;
	}
	else if(data < node->data){
		return searchHelper(node->left,data);
	}
	else if(data > node->data){
		return searchHelper(node->right,data);
	}
	else{
		cout<<endl<<"Not Found:"<<data<<endl;
		return NULL;
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
//Find the parent of a node

int BST::parentNode(int data){
	if(root == NULL){
			cout<<endl<<"Empty tree"<<endl;
			return -1;
		}
		else{
			cout<<search(data);
			if(search(data)){
				if(parentNodeHelper(root,data)){
					cout<<endl;
					return (parentNodeHelper(root,data))->data;
				}
				else{
					cout<<endl<<"Parent of root is NULL"<<endl;
					return 0;
				}
			}

			else return -1;
		}
}

Node *BST::parentNodeHelper(Node *node,int data){
	static Node * parent = NULL;
	if(data == node->data){
		return parent;
	}
	else if(data < node->data){
			parent = node;
			parentNodeHelper(node->left,data);
		}
		else if(data > node->data){
			parent = node;
			parentNodeHelper(node->right,data);
		}
	return parent;
}


//Find lowest Common Ancestor for any two given nodes
int BST::lowestCommonAncestor(int node1,int node2){
	int index1,index2;
	for(int i=0;i<globalLenInorder;i++){
		if(globalInorder[i] == node1){
			index1 = i;
		}
		if(globalInorder[i] == node2){
					index2 = i;
				}
	}
	int rank=-1;
	for(int j=index1;j<index2;j++){
		for(int k=0;k<globalLenPostorder;k++){
			if(globalInorder[j] == globalPostorder[k]){
				if(k>rank){
					rank =k;
				}
			}
		}
	}
	return globalPostorder[rank];
}
//Find if the BST has a path of a particular sum
bool BST::hasPathSum(int sum){
	if(root == NULL){
		cout<<endl<<"Empty tree"<<endl;
		return sum==0;
	}
	else{
		return hasPathSumHelper(root,sum);
	}
}
bool BST::hasPathSumHelper(Node* node,int sum){
	if(node == NULL){
		return sum==0;
	}
	int subsum=sum-node->data;
	return hasPathSumHelper(node->left,subsum)||hasPathSumHelper(node->right,subsum);
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
		globalInorder[globalLenInorder++]=node->data; //For finding lowest common ancestor
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
		globalPostorder[globalLenPostorder++]=node->data; //For finding lowest common ancestor
	}
}
//Postorder using itertaive version
void BST::postorderIterative(){
	if(root == NULL){
			cout<<"BST empty";
		}
		else{
			postorderIterativeHelper(root);
		}
}
void BST::postorderIterativeHelper(Node *node){
	//Using stack
	stack <Node *> input;
	stack <Node *> output;
	if(node){
		input.push(node);
		while(!input.empty()){
			Node *tmp = input.top();
			input.pop();
			output.push(tmp);
			if(tmp->left){
				input.push(tmp->left);
			}
			if(tmp->right){
				input.push(tmp->right);
						}

		}
	}
	cout<<endl<<"Output:"<<endl;
	while(!output.empty()){
		cout<<output.top()->data<<"->";
		output.pop();
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
	if(node == NULL){
		return;
	}
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
	if((node1 && !node2) || (!node1 && node2)){
			return false;
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

//To delete all nodes of a BST
void BST::deleteBST(){
     if(root == NULL){
    	 cout<<"BST is empty.Nothing to delete.";
     }
     else{
    	 deleteBSTHelper(&root);
     }
}

void BST::deleteBSTHelper(Node **node){
	if((*node) == NULL){
		return;
	}
	deleteBSTHelper(&(*node)->left);
	deleteBSTHelper(&(*node)->right);
	if((*node)->left == NULL && (*node)->right == NULL){
		delete *node;
		*node = NULL;
	}
}
