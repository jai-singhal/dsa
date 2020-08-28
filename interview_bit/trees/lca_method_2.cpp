/* C++ Program to find LCA of n1 and n2 using one traversal of Binary Tree */
#include <iostream> 

using namespace std; 

// A Binary Tree Node 
struct Node 
{ 
	struct Node *left, *right; 
	int key; 
}; 

// Utility function to create a new tree Node 
Node* newNode(int key) 
{ 
	Node *temp = new Node; 
	temp->key = key; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

// This function returns pointer to LCA of two given values n1 and n2. 
// This function assumes that n1 and n2 are present in Binary Tree 
struct Node *findLCA(struct Node* root, int n1, int n2) { 
	if(root == NULL)
		return NULL;

	if(root ->key == n1 || root->key == n2){
		return root;
	}
	Node* left = findLCA(root->left, n1, n2);
	Node* right = findLCA(root->right, n1, n2);
	if(left != NULL && right != NULL)
		return root;
	if(left != NULL)
		return findLCA(root->left, n1, n2);
	if(right != NULL)
		return findLCA(root->right, n1, n2);
	return NULL;
} 

// Driver program to test above functions 
int main() 
{ 
	// Let us create binary tree given in the above example 
	Node * root = newNode(1); 
	root->left = newNode(2); 
	root->right = newNode(3); 
	root->left->left = newNode(4); 
	root->left->right = newNode(5); 
	root->right->left = newNode(6); 
	root->right->right = newNode(7); 
	cout << "LCA(2, 7) = " << endl << findLCA(root, 2, 6)->key; 
	// cout << "nLCA(4, 6) = " << findLCA(root, 4, 6)->key; 
	// cout << "nLCA(3, 4) = " << findLCA(root, 3, 4)->key; 
	// cout << "nLCA(2, 4) = " << findLCA(root, 2, 4)->key; 
	return 0; 
}
