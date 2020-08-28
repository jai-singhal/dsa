// https://www.interviewbit.com/problems/invert-the-binary-tree/

#include<iostream>
#include<vector>
using namespace std;

// Definition for binary tree
struct TreeNode {     
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode* invertTree(TreeNode* root) {
    if(root == NULL)
        return root;
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    invertTree(root->left);
    invertTree(root->right);
    return root;
}