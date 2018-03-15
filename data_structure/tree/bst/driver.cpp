#include<iostream>
#include "bst.h"
using namespace std;

int main(void){
    BST myTree = BST();
    Node* root = NULL;
    root = myTree.insertNode(root, 5);
    root = myTree.insertNode(root, 10);
    root = myTree.insertNode(root, 2);
    root = myTree.insertNode(root, 6);
    root = myTree.insertNode(root, 9);
    root = myTree.insertNode(root, 1);
    root = myTree.insertNode(root, 4);

    myTree.preOrder(root); cout << endl;

    myTree.searchNode(root, 2);

    root = myTree.deleteNode(root, 2);
    myTree.preOrder(root); cout << endl;

    int x = 1;
    myTree.kthSmallestElement(root, 3, x);
    return 0;
}