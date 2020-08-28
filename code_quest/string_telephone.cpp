#include<iostream>
#include<list>

using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};

node* createNode(int data){
    node* newNode = new node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

bool checkTravelled(int numb, list<int> arr, int n){
    list<int>::iterator it;
    for(it = arr.begin(); it != arr.end(); it++){
        if(*it == numb)
            return true;
    }
    return false;
}


node* insertNode(node* current, node* past, int connect, int data){
    node* newNode = createNode(data);
    if(current == NULL)
        return current;
        
    if(current->data == data){
        
    }

    insertNode(current->left, current, connect, data);
    insertNode(current->right, current, connect, data);
    
}

node* createTree(int n, int input1[], int input2[]){
    list<int> unTravalled;
    list<int> travelled;
    node* root, *node1, *node2;
    
    for(int i = 0; i < n-1; i++){
        node1 = createNode(input1[i]); 
        node2 = createNode(input2[i]);
        if(root == NULL){
            root = node1;
            root->left = node2;
            travelled.push_front(input1[i]);
            travelled.push_front(input2[i]);
            continue;
        }
        
        if(!checkTravelled(input1[i], travelled, n) && !checkTravelled(input2[i], travelled, n)){
            unTravalled.push_front(input1[i]);
            unTravalled.push_front(input2[i]);
            continue;
        }

        if(checkTravelled(input1[i], travelled, n) && checkTravelled(input2[i], travelled, n)){
            continue;
        }

        if(!checkTravelled(input1[i], travelled, n)){
            continue;
        }
        if(!checkTravelled(input2[i], travelled, n)){
            continue;
        }
            
    }
}
