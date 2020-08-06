#include<iostream>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

struct node{
    int data;
node* left, *right;
};

node* createNode(int data){
    node* newNode = new node();
    newNode->data = data;
    return newNode;
}


void printRoot2Leaf(node* root, vector<int> path, int pathLen){
    if(root == nullptr)
        return;
    path[pathLen++] = root->data;

    if(!root->left && !root->right){
        for(auto p: path)
            if(p!=INT_MAX)
                cout << p << " ";
        cout << endl;
    }
    else{
        printRoot2Leaf(root->left, path, pathLen);
        printRoot2Leaf(root->right, path, pathLen);
    }
}

bool sumFindRoot2Leaf(node* root, int findSum, int sum){
    if(root == nullptr)
        return false;
    sum += root->data;
    if(!root->left && !root->right){
        if(findSum == sum){
            return true;
        }
    }
    else{
        return 
            sumFindRoot2Leaf(root->left, findSum, sum) || 
            sumFindRoot2Leaf(root->right,findSum, sum);
    }
    return false;
}


int main(){
    node* head = createNode(1);
    node* temp1 = head->left = createNode(2);
    node* temp2 = head->right = createNode(3);
    temp1->left = createNode(4);
    temp1->right = createNode(5);
    temp1->right->left = createNode(-1);

    temp2->left = createNode(6);
    temp2->right = createNode(7);
    temp2->right->right = createNode(9);
    temp2->right->left = createNode(8);

    vector<int> path(10, INT_MAX);

    printRoot2Leaf(head, path, 0);
    cout << endl;
    cout << sumFindRoot2Leaf(head, 20, 0);
}