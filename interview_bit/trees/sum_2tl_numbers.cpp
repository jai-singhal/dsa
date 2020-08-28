// https://www.interviewbit.com/problems/sum-root-to-leaf-numbers/
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

void sumNumbersUtils(TreeNode* root, long long int r2l, int &total_sum) {
    if(root == NULL)
        return;
    r2l = (r2l*10 + root->val)%1003;
    if(root->left == NULL && root->right == NULL){ // leaf
        total_sum = (total_sum%1003 + r2l%1003)%1003;
    }

    if(root->left != NULL)
        sumNumbersUtils(root->left, r2l, total_sum);
    if(root->right != NULL)
        sumNumbersUtils(root->right, r2l, total_sum);
    r2l = r2l/10; // backtrack

}
 
int sumNumbers(TreeNode* A) {
    int total_sum = 0;
    sumNumbersUtils(A, 0, total_sum);
    return total_sum;
}