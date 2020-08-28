// https://www.interviewbit.com/problems/cousins-in-binary-tree/
#include<iostream>
#include<vector>
#include<stack>

using namespace std;

// Definition for binary tree
struct TreeNode {     
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


int kthsmallest(TreeNode* root, int k) {
    // inorder
    // for practice lets do with stack
    stack<TreeNode*> s;
    // s.push(root);
    TreeNode* curr = root;
    while(curr != NULL || !s.empty()){
        while(curr != NULL){
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        k--;
        if(k == 0)
            return curr->val;
        curr = curr->right;
    }
    return -1;
}