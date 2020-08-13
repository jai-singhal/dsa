// https://www.interviewbit.com/problems/path-sum/

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

int hasPathSum(TreeNode* node, int sum) {
    if (node == NULL) 
        return (sum == 0); 
    else { 
        bool ans = 0;   
        /* otherwise check both subtrees */
        int subSum = sum - node->val; 
        /* If we reach a leaf node and sum becomes 0 then return true*/
        if ( subSum == 0 && node->left == NULL && node->right == NULL ) 
        return 1;
        if (node->left) 
            ans = ans || hasPathSum(node->left, subSum); 
        if (node->right) 
            ans = ans || hasPathSum(node->right, subSum); 
        return ans; 
    }
}