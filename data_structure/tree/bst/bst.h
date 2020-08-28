#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* left, *right;
        Node(int data){
            this->data = data;
            this->left = this->right = NULL;
        }
};

class BST{
    public:
        Node* insertNode(Node* root, int data){
            if(root == NULL){
                Node* newNode = new Node(data);
                return newNode;
            }
            if(root->data < data)
                root->right = insertNode(root->right, data);
            
            else if (root->data >= data)
                root->left = insertNode(root->left, data);

            return root;
        } 

        Node* searchNode(Node* root, int key){
            if(root == NULL) return root;
            
            if(root->data == key){
                cout << "Key found!!" << endl;
                return root;
            }
            if(root->data < key)
                searchNode(root->right, key);
            
            else if (root->data > key)
                searchNode(root->left, key);
        
            return root;
        } 

        Node* deleteNode(Node* root, int key){
            if(root == NULL) return root;

            if(root->data < key)
                root->right = deleteNode(root->right, key);
            
            else if (root->data > key)
                root->left = deleteNode(root->left, key);

            //key found
            else{
                if(root->left == NULL){
                    Node* temp = root->right;
                    delete root;
                    return temp;
                }
                if(root->right == NULL){
                    Node* temp = root->left;
                    delete root;
                    return temp;
                }            
                Node* inorderSucc = inorderSucessive(root->right);
                root->data = inorderSucc->data;
                root->right = deleteNode(root->right, inorderSucc->data);
            }
            return root;
        }    

        Node* inorderSucessive(Node* root){
            if(root == NULL)    return root;
            while(root->left != NULL)
                root = root->left;
            
            return root;
        }  

        void inOrder(Node* root){
            if(root == NULL)    return;
            inOrder(root->left);
            cout << root->data << " ";
            inOrder(root->right);
        } 

        void preOrder(Node* root){
            if(root == NULL)    return;
            cout << root->data << " ";
            preOrder(root->left);
            preOrder(root->right);
        }    

        void postOrder(Node* root){
            if(root == NULL)    return;
            postOrder(root->left);
            postOrder(root->right);
            cout << root->data << " ";
        }  

        int kthSmallestElement(Node* root,  int k, int &count){
            if(root == NULL)    return -1;
            
            kthSmallestElement(root->left, k, count);
            if(count == k){
                cout << k << "rd/th smallest number is: " << root->data << endl;
                count = -1;
                return root->data;
            }
            else
                count++;
            kthSmallestElement(root->right, k, count);        
        }  
        
};

