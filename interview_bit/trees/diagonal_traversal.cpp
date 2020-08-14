// https://www.interviewbit.com/problems/diagonal-traversal/
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

vector<int> solve(TreeNode* root) {
    vector<int> diagonal;
    if(root == NULL)
        return diagonal;
    queue<TreeNode*> s;
    TreeNode* curr = root;
    while(curr != NULL || !s.empty()){
        while(curr != NULL){
            s.push(curr);
            diagonal.push_back(curr->val);
            curr = curr->right;
        }
        curr = s.front();
        s.pop();
        curr = curr->left;
            
    }
    return diagonal;
}