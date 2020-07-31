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

vector<int> reverseLevelOrder(node* head){
    queue<node*>q;
    vector<int> solution;
    stack<int>s;
    node* temp;
    q.push(head);
    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(temp->right){
            q.push(temp->right);
        }
        if(temp->left){
            q.push(temp->left);
        }
        s.push(temp->data);
    }
    while(!s.empty()){
        solution.push_back(s.top());
        s.pop();
    }
    return solution;
}

vector<int> levelOrder(node* head){
    queue<node*>q;
    vector<int> solution;
    node* temp;
    q.push(head);
    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
        solution.push_back(temp->data);
    }
    return solution;
}

int main(){
    node* head = createNode(1);
    node* temp1 = head->left = createNode(2);
    node* temp2 = head->right = createNode(3);
    temp1->left = createNode(4);
    temp1->right = createNode(5);
    temp2->left = createNode(6);
    temp2->right = createNode(7);

    vector<int> solution1 = reverseLevelOrder(head);
    for(auto s: solution1)
        cout << s << " ";
    cout << endl;

    vector<int> solution2 = levelOrder(head);
    for(auto s: solution2)
        cout << s << " ";
    cout << endl;

    return 0;
}