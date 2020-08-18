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
struct Node *findLCA(struct Node* root, int n1, int n2) 
{ 
	// Base case 
	if (root == NULL) return NULL; 

    cout << "call("<< root->key << ")" << endl;


	// If either n1 or n2 matches with root's key, report 
	// the presence by returning root (Note that if a key is 
	// ancestor of other, then the ancestor key becomes LCA 
	if (root->key == n1 || root->key == n2) 
		return root; 

	// Look for keys in left and right subtrees 
	Node *left_lca = findLCA(root->left, n1, n2); 
	Node *right_lca = findLCA(root->right, n1, n2); 

	// If both of the above calls return Non-NULL, then one key 
	// is present in once subtree and other is present in other, 
	// So this node is the LCA 
	if (left_lca && right_lca){
        cout << "Both: " << left_lca->key << " " << right_lca->key << endl;
        return root;
    }  

	// Otherwise check if left subtree or right subtree is LCA 
	return (left_lca != NULL)? left_lca: right_lca; 
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
