#include<iostream>
#include<vector>
#include<stack>
using namespace std;


//  * Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


vector<int> preorderTraversal(TreeNode* root) {
    stack<TreeNode*> s;
    vector<int> solution;
    if(root == NULL) return solution;
    TreeNode* curr = root;
    while(curr != NULL || !s.empty()){
        while(curr != NULL){
            solution.push_back(curr->val);
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        curr = curr->right;
    }
    return solution;
}

vector<int> inorderTraversal(TreeNode* root) {
    stack<TreeNode*> s;
    vector<int> solution;
    if(root == NULL) return solution;
    TreeNode* curr = root;
    while(curr != NULL || !s.empty()){
        while(curr != NULL){
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        solution.push_back(curr->val);
        s.pop();
        curr = curr->right;
    }
    return solution;
}