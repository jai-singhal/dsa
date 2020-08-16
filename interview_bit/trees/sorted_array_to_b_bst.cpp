// https://www.interviewbit.com/problems/cousins-in-binary-tree/
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


TreeNode* sortedArrayToBSTUtil( const vector<int> &A, int l, int r) {
     if(l > r)
        return NULL;
    int mid = (l+r)/2;    
    TreeNode* root = new TreeNode(A[mid]);
    root->left = sortedArrayToBSTUtil(A, l, mid-1);
    root->right = sortedArrayToBSTUtil(A, mid+1, r);
    return root;
}

TreeNode* sortedArrayToBST(const vector<int> &A) {
    int n = A.size();
    if(n == 0)
        return NULL;
    TreeNode* root = sortedArrayToBSTUtil(A, 0, n-1);
    return root;  
}