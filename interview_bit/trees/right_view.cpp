// https://www.interviewbit.com/problems/right-view-of-binary-tree/
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
    vector<int> solution;
    if(root == NULL)
        return solution;
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    int lastElement;
    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();
        if(temp == NULL){
            if(!q.empty())
                q.push(NULL);
            solution.push_back(lastElement);
        }
        else{
            if(temp->left != NULL)
                q.push(temp->left);
            if(temp->right != NULL)
                q.push(temp->right);
            lastElement = temp->val;
        }
    }
    return solution;
}