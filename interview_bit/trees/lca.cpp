// https://www.interviewbit.com/problems/cousins-in-binary-tree/
#include<iostream>
#include<vector>
#include<stack>
#include<map>

using namespace std;

// Definition for binary tree
struct TreeNode {     
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


void fillParents(TreeNode* root, map<int, int> &parent){
    if(root == NULL)
        return;
    if(root->left != NULL){
        parent.insert({root->left->val, root->val});
        fillParents(root->left, parent);
    }
    if(root->right != NULL){
        parent.insert({root->right->val, root->val});
        fillParents(root->right, parent);
    }
        
} 

int lca(TreeNode* root, int val1, int val2) {
    map<int,int> parent;
    parent.insert({root->val, INT_MAX});
    fillParents(root, parent);

    if(parent.find(val1) == parent.end() || parent.find(val2) == parent.end())
        return -1;
        
    stack<int> sv1, sv2;
    int p1 = val1;
    int p2 = val2;
    
    while(p1 != INT_MAX){
        sv1.push(p1);
        p1 = parent[p1];
    }

    while(p2 != INT_MAX){
        sv2.push(p2);
        p2 = parent[p2];
    }

    int lastParent;
    while(sv1.top() == sv2.top()){
        lastParent = sv1.top();
        sv1.pop();
        sv2.pop();
        if(sv1.empty() || sv2.empty())
            break;
    }
    return lastParent;
}

int main(){
    TreeNode* head = new TreeNode(3);
    TreeNode* temp1 = head->left = new TreeNode(5);
    TreeNode* temp2 = head->right = new TreeNode(1);
    temp1->left = new TreeNode(6);
    temp1->right = new TreeNode(2);

    temp1->right->left = new TreeNode(7);
    temp1->right->right = new TreeNode(4);

    temp2->left = new TreeNode(0);
    temp2->right = new TreeNode(8);
    int sol;

    sol = lca(head, 7, 0);
    cout << "7 and 0: ";
    cout << sol << endl;

    sol = lca(head, 0, 1);
    cout << "0 and 1: ";
    cout << sol << endl;

    sol = lca(head, 6, 4);
    cout << "6 and 4: ";
    cout << sol << endl;

    sol = lca(head, 3, 3);
    cout << "3 and 3: ";
    cout << sol << endl;

    sol = lca(head, 1, 1);
    cout << "1 and 1: ";
    cout << sol << endl;    
    
}