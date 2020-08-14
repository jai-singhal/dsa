vector<int> Solution::preorderTraversal(TreeNode* root) {
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

vector<int> Solution::inorderTraversal(TreeNode* root) {
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