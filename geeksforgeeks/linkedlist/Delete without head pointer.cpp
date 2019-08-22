//Delete without head pointer
// https://practice.geeksforgeeks.org/problems/delete-without-head-pointer/1
#include<iostream>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}*head;


// code here function only
void deleteNode(Node *node){
    if(node->next == NULL){
        node = NULL;
        delete node;
        return;
    }
        
    node->data = node->next->data;
    Node* temp = node->next;
    node->next = node->next->next;
    delete temp;
}
