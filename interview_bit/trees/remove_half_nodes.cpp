// https://www.interviewbit.com/problems/remove-half-nodes/

#include<iostream>
#include<vector>
using namespace std;

//  Definition for binary tree
struct TreeNode {     
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* solve(TreeNode* root) {
    if(root == NULL)
        return root;
    
    root->left = solve(root->left);
    root->right = solve(root->right);
    
    if(root->left == NULL && root->right == NULL)
        return root;
    if(root->left == NULL && root->right != NULL){
        TreeNode* temp = root->right;
        delete root;
        return temp;
    }
    if(root->right == NULL && root->left != NULL){
        TreeNode* temp = root->left;
        delete root;
        return temp;
    }  
    return root;
}
