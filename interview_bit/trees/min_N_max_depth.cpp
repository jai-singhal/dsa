// https://www.interviewbit.com/problems/max-depth-of-binary-tree/
#include<iostream>
#include<algorithm>
using namespace std;

// Definition for binary tree
struct TreeNode {     
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int minDepth(TreeNode* root) {
    if(root == NULL)
        return 0;
    int ldepth = minDepth(root->left);
    int rdepth = minDepth(root->right);
    
    if(ldepth == 0)
        return 1+ rdepth;
    else if(rdepth == 0)
        return 1+ldepth;
    else
        return 1 + min(ldepth, rdepth);
}

int maxDepth(TreeNode* root) {
    if(root == NULL)
        return 0;
    return 1+max(maxDepth(root->left), maxDepth(root->right));
}