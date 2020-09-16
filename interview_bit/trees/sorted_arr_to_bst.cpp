// https://www.interviewbit.com/problems/path-sum/

#include<iostream>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

// Definition for binary tree
struct TreeNode {     
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode* createBSTFromArr(vector<int> arr, int l, int r){
    if(l > r)
        return NULL;
    
    int mid = l + (r-l)/2;
    TreeNode* newNode = new TreeNode(arr[mid]);
    newNode->left = createBSTFromArr(arr, l, mid-1);
    newNode->right = createBSTFromArr(arr, mid+1, r);
    return newNode;
}



void LevelOrder(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();
        cout << temp->val << " ";
        if(temp == NULL){
            continue;
        }
        else{
            if(temp->left != NULL)
                q.push(temp->left);
            if(temp->right != NULL)
                q.push(temp->right);

        }
    }
}
void preOrder(TreeNode* root){
    stack<TreeNode*> s;
    TreeNode* curr = root;
    while(curr != NULL || !s.empty()){
        while(curr != NULL){
            s.push(curr);
            cout << curr->val << " ";
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        curr = curr->right;
    }
}

void inOrder(TreeNode* root){
    stack<TreeNode*> s;
    TreeNode* curr = root;
    while(curr != NULL || !s.empty()){
        while(curr != NULL){
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        cout << curr->val << " ";
        s.pop();
        curr = curr->right;
    }
}


void inOrderRec(TreeNode* root){
    if(root == NULL)
        return;
    inOrderRec(root->left);
    cout << root->val << " ";
    inOrderRec(root->right);
}



int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    TreeNode* root = createBSTFromArr(arr, 0, arr.size()-1);
    LevelOrder(root);
    cout << endl;
    inOrderRec(root);
    cout << endl;
    inOrder(root);

    cout << endl;
    preOrder(root);
}