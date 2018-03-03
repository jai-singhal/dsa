#include<iostream>
using namespace std;

class TreeNode{
    public:
        int data;
        TreeNode* left;
        TreeNode* right;
        int balance_factor;

    // public:
        TreeNode(int data){
            this->data = data;
            this->left = this->right = NULL;
            this->balance_factor = 0;
        }
};

class AvlTree{
    public:

        TreeNode* insertNode(TreeNode* root, int data){
            if(root == NULL)
                return new TreeNode(data);
            else if(root->data <= data)
                root->right = insertNode(root->right, data);
            else
                root->left = insertNode(root->left, data);

            root->balance_factor = getHeight(root->right) - getHeight(root->left);
            
            if(root->balance_factor > 1 || root->balance_factor < -1)
                root = balanceTree(root);

            return root;
        }

        int getHeight(TreeNode* root){
            if(root == NULL)    return 0;
            return 1 + max(getHeight(root->left) , getHeight(root->right));
        }

        TreeNode* balanceTree(TreeNode* root){
            int bf = root->balance_factor;
            cout << "bt called " << root->data;
            if(bf < -1){ //right rotate
                 root = rightRotate(root);
            }
            else if(bf > 1){ //left rotate
                root = leftRotate(root);
            }
            return root;
        }

        TreeNode* leftRotate(TreeNode* root){
            TreeNode* rightChild = root->right;
            root->right = rightChild->left;
            rightChild->left = root;

            root->balance_factor = getHeight(root->right) - getHeight(root->left);
            return rightChild;
        }

        TreeNode* rightRotate(TreeNode* root){
            TreeNode* leftChild = root->left;
            root->left = leftChild->right;
            leftChild->right = root;

            root->balance_factor = getHeight(root->right) - getHeight(root->left);
            return leftChild;
        }

        void preOrder(TreeNode* root){
            if(root != NULL){
                cout << root->data << " " << root->balance_factor <<  endl;
                preOrder(root->left);
                preOrder(root->right);
            }
        }

        void print2D(TreeNode *root, int space = 2){
            if (root == NULL)   return;
            space += 8;
            print2D(root->right, space);
            printf("\n");
            for (int i = 8; i < space; i++)
                printf(" ");
            printf("%d\n", root->data);
            print2D(root->left, space);
        }
        
};

int main(){
    AvlTree myTree = AvlTree();
    TreeNode* root = NULL;

    root = myTree.insertNode(root, 13);
    root = myTree.insertNode(root, 10);
    root = myTree.insertNode(root, 15);
    root = myTree.insertNode(root, 5);
    root = myTree.insertNode(root, 11);
    root = myTree.insertNode(root, 16);
    root = myTree.insertNode(root, 4);
    root = myTree.insertNode(root, 6);
    root = myTree.insertNode(root, 14);
    root = myTree.insertNode(root, 1);   

    root = myTree.insertNode(root, 8);
    // root = myTree.insertNode(root, 2);
    // root = myTree.insertNode(root, 12); 

    // root = myTree.insertNode(root, 3); 
    // root = myTree.insertNode(root, 20);
    // root = myTree.insertNode(root, 6);
    cout << "Preorder Traversal of tree: " << endl;
    myTree.print2D(root);
    cout << endl;

    cout << "Height of tree: " << myTree.getHeight(root) << endl;
    return 0;

}
