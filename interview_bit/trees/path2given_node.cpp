// https://www.interviewbit.com/problems/path-to-given-node/

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


bool solveUtil(TreeNode* root, int B, vector<int> &r2l) {
    if(root == NULL)
        return false;

    r2l.push_back(root->val);
    if(root->val == B)
        return true;

    bool left = false, right = false;

    if(root->left != NULL)
        left = solveUtil(root->left, B, r2l);
    if(root->right != NULL)
        right = solveUtil(root->right, B, r2l);   
        
    if(left || right)
        return true;
    
    r2l.pop_back();
    return false;

    // return r2l;
}

vector<int> solve(TreeNode* root, int B) {
    // int height = maxHeight(root);
    
    vector<int> r2l;
    solveUtil(root, B, r2l);
    return r2l;
    
}
