// https://www.interviewbit.com/problems/populate-next-right-pointers-tree/
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

//  * Definition for binary tree with next pointer.
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
 
void connect(TreeLinkNode* root) {
    
    if(root == NULL)
        return;
        
    queue<TreeLinkNode*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        TreeLinkNode* temp = q.front();
        q.pop();
        if(temp == NULL){
            if(!q.empty())
                q.push(NULL);
        }
        else{
            if(!q.empty())
                temp->next = q.front();
            
            if(temp->left != NULL)
                q.push(temp->left);
            if(temp->right != NULL)
                q.push(temp->right);
                
        }
    }
}
