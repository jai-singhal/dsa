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

bool structure_similar(node* head1, node* head2){
    if(head1 == nullptr && head2 == nullptr)
        return true;
    if(head1 == nullptr || head2 == nullptr)
        return false;
    return (head1->data == head2->data) &&
        structure_similar(head1->left, head2->left) &&
        structure_similar(head1->right, head2->right);
}

int diameterUtil(node* head){
    if(head == nullptr)
        return 0;
    return 1 + max(diameterUtil(head->left), diameterUtil(head->right));
}

int diameter(node* head){
    if(head == nullptr)
        return 0;
    return 1 + diameterUtil(head->left) + diameterUtil(head->right);
}

void mirrorOfTree(node* head){
    if(head == nullptr)
        return;
    
}

int main(){
    node* head1 = createNode(1);
    node* temp1 = head1->left = createNode(2);
    node* temp2 = head1->right = createNode(3);
    temp1->left = createNode(4);
    temp1->right = createNode(5);
    temp1->right->right = createNode(66);

    temp2->left = createNode(6);
    temp2->right = createNode(7);
    temp2->right->right = createNode(9);
    temp2->right->left = createNode(8);



    node* head2 = createNode(1);
    temp1 = head2->left = createNode(2);
    temp2 = head2->right = createNode(3);
    temp1->left = createNode(4);
    temp1->right = createNode(5);
    temp2->left = createNode(6);
    temp2->right = createNode(7);
    cout << structure_similar(head1, head2) << endl;

    cout << diameter(head1) << endl;

    return 0;
}


s1 = "valya"
s2= "lyglb"
s3 = "vldoh"

to_search = "val"

{
    'v': [[0], [], [0]],
    'a': [[1,4], [], []],
    'l': [[2], [0, 3], [1]],
}