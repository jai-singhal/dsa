#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<unordered_map>
#include<map>

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

int tree_height(node* head){
    queue<node*>q;
    node* temp;
    q.push(head);
    int height = 0;
    q.push(nullptr);
    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(temp == nullptr){
            if(!q.empty())
                q.push(nullptr);
            height++;
        }
        else {
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
    return height;
}

#define PNI pair<node*, int>
vector<int> verticalOrder(node* root){
    queue<PNI> q;
    map<int, vector<int>> hori_map;
    vector<int> solution;
    int hd = 0;
    q.push(PNI(root, hd));
    while(!q.empty()){
        PNI temp = q.front();
        q.pop();
        hd = temp.second;
        node* tnode = temp.first;
        // cout << tnode->data << " ";
        hori_map[hd].push_back(tnode->data);

        if(tnode->left){
            q.push(PNI(tnode->left, hd-1));
        }
        if(tnode->right){
            q.push(PNI(tnode->right, hd+1));
        }
    }
    for(auto a:hori_map){
        // cout << a.first << "::";
        for(auto i: a.second)
            solution.push_back(i);
    }
    return solution;
}

int height(node* root){
    if(root == NULL)    return 0;
    return 1 + max(
        height(root->left),
        height(root->right)
    );
}

void recursiveLevelOrderUtil(node* root, int h){
    if(h == 0)
        return;
    if(h==1)
        cout << root->data << " ";
    else{
        recursiveLevelOrderUtil(root->left, h-1);
        recursiveLevelOrderUtil(root->right, h-1);
    }
    
}

void recursiveLevelOrder(node* root){
    int h = height(root);
    for(int i = 1; i <= h; i++){
        recursiveLevelOrderUtil(root, i);
    }
}

int main(){
    node* head = createNode(1);
    node* temp1 = head->left = createNode(2);
    node* temp2 = head->right = createNode(3);
    temp1->left = createNode(4);
    temp1->right = createNode(5);
    temp2->left = createNode(6);
    temp2->right = createNode(7);

    // vector<int> solution1 = reverseLevelOrder(head);
    // for(auto s: solution1)
    //     cout << s << " ";
    // cout << endl;

    vector<int> solution2 = levelOrder(head);
    for(auto s: solution2)
        cout << s << " ";
    cout << endl;

    // cout << tree_height(head);
    vector<int> VOSol = verticalOrder(head);
    for(auto s: VOSol)
        cout << s << " ";
    cout << endl;

    recursiveLevelOrder(head);
    
    return 0;
}