// https://www.interviewbit.com/problems/root-to-leaf-paths-with-sum/


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

void pathSumUtil(TreeNode* root, int B, 
        vector<int> pathSum, vector<vector<int>> &sol) 
{
    if(root ==  NULL)
        return;
    pathSum.push_back(root->val);
    int psum = B - root->val;
    if(psum == 0 && root->left == NULL && root->right == NULL){
        sol.push_back(pathSum);
    }
    if(root->left != NULL)
        pathSumUtil(root->left, psum, pathSum, sol);
        
    if(root->right != NULL)
        pathSumUtil(root->right, psum, pathSum, sol);
    pathSum.pop_back(); //backtrack
}
 
vector<vector<int>> pathSum(TreeNode* root, int B) {
    vector<vector<int>> sol;
    vector<int> pathSum;
    pathSumUtil(root, B, pathSum, sol);
    return sol;
}