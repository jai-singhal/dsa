// https://www.interviewbit.com/problems/sorted-array-to-balanced-bst/
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


#define PA pair<TreeNode*, TreeNode*>

vector<int> solve(TreeNode* root, int key) {
    vector<int> solution;
    if(root == NULL)
        return solution;
        
    queue<PA> q;
    q.push(make_pair(root, nullptr));
    q.push(make_pair(nullptr, nullptr));
    vector<PA> level;
    bool found = false;
    TreeNode* parent = nullptr;
    
    while(!q.empty()){
        PA temp = q.front();
        q.pop();
        if(temp.first == nullptr){
            if(!q.empty())
                q.push(make_pair(nullptr, nullptr));

            if(found) break;
            
            level.clear();
        }
        else{
            if(temp.first->val == key){
                parent = temp.second;
                found = true;
            }
            else
                level.push_back(make_pair(temp.first, temp.second));
                
            if(temp.first->left != NULL)
                q.push(make_pair(temp.first->left, temp.first));
            if(temp.first->right != NULL)
                q.push(make_pair(temp.first->right, temp.first));
        }
    }
    for(auto s: level){
        if(s.second == parent)
            continue;
        solution.push_back(s.first->val);
    }

    return solution;
}