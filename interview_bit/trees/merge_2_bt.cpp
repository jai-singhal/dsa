// https://www.interviewbit.com/problems/merge-two-binary-tree/
#include<iostream>
using namespace std;
// Definition for binary tree
struct TreeNode {     
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode* mergeTwoBinaryTree(TreeNode* root1, TreeNode* root2) {
    if(root1 == NULL && root2 == NULL)
        return NULL;
    
    TreeNode* root;
    if(root1 != NULL && root2 != NULL){
        root = new TreeNode(root1->val + root2->val);
        root->left = mergeTwoBinaryTree(root1->left, root2->left);
        root->right = mergeTwoBinaryTree(root1->right, root2->right);
    }
    else if(root1 != NULL){
        root = new TreeNode(root1->val);
        root->left = mergeTwoBinaryTree(root1->left, root2);
        root->right = mergeTwoBinaryTree(root1->right, root2);
    }
    else if(root2 != NULL){
        root = new TreeNode(root2->val);
        root->left = mergeTwoBinaryTree(root1, root2->left);
        root->right = mergeTwoBinaryTree(root1, root2->right);
    }
    return root;
}