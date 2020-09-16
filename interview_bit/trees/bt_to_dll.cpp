#include<iostream>
#include<vector>

using namespace std;


//  * Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left; //previous
    TreeNode *right; // next
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void flattentoSLL(TreeNode* root) {
    if(root == NULL || 
        (root->left == NULL && root->right == NULL))
        return;
    if(root->left != NULL){
        flattentoSLL(root->left);

        TreeNode* temp = root->right;
        root->right = root->left;
        root->left = NULL;
        
        TreeNode* t = root->right; 
        while (t->right != NULL) { 
            t = t->right; 
        }
        t->right = temp;
    }   
    flattentoSLL(root->right);
}

void printSLL(TreeNode* root){
    TreeNode* temp = root;
    while(temp != NULL){
        cout << temp->val << " ";
        temp = temp->right;
    }
}

void flattentoDLL(TreeNode* root, TreeNode** head) {
    if(root == NULL)
        return;

    static TreeNode* prev = NULL;

    flattentoDLL(root->left, head);

    if(prev == NULL)
        *head = root;
    else{
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    flattentoDLL(root->right, head);
}




int main(){
    TreeNode* root = new TreeNode(10);
    TreeNode* temp1 = root->left = new TreeNode(12);
    TreeNode* temp2 = root->right = new TreeNode(15);
    temp1->left = new TreeNode(25);
    temp1->right = new TreeNode(30);
    temp2->left = new TreeNode(36);
    // temp2->right = new TreeNode(7);
    
    TreeNode** head;
    flattentoDLL(root, head);
    printSLL(*head);


}