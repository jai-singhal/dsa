// https://www.interviewbit.com/problems/balanced-binary-tree/
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// Definition for binary tree
struct TreeNode {     
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int height(TreeNode* root){
    if(root == NULL)
        return 0;
    return 1+max(height(root->left), height(root->right));
}

int isBalanced(TreeNode* root) {
    if(root == NULL)
        return 1;

    int lh = height(root->left);
    int rh = height(root->right);
    if(abs(lh-rh) <= 1) 
        if(isBalanced(root->left) && isBalanced(root->right))
            return 1;
    return 0;
}