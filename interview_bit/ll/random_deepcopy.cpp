#include<iostream>
using namespace std;

struct Node{
    int data; 
    Node *next,*random; 
    Node(int x) { 
        data = x; 
        next = random = NULL; 
    }
};

// Utility function to print the list. 
void print_list(Node *start) { 
    Node *ptr = start; 
    while (ptr) { 
        cout << ptr << ":: Data = " << ptr->data << ", Random  = "
             << ptr->random->data << endl; 
        ptr = ptr->next; 
    } 
} 

Node* cloned_list(Node* head){
    Node* temp, *newNode, *t;
    temp = head;
    while(temp!=NULL){
        newNode = new Node(temp->data);
        // t = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
        temp = temp->next->next;
    }

    temp = head;
    while(temp!=NULL){
        t = temp->next;
        if(temp->random == NULL) 
            t->random = NULL;
        else
            t->random = temp->random->next;
        temp = temp->next->next; // temp = t->next;
    }

    temp = head;
    // if(temp == NULL) return temp;
    Node* newHead = temp->next;
    while(temp!=NULL){
        t = temp->next;
        temp->next = t->next;
        temp = temp->next; // temp = t->next;
        if(temp==NULL) 
            t->next = NULL;
        else
            t->next = temp->next;
    }
    return newHead;
}


// Driver code 
int main() 
{ 
    Node* start = new Node(1); 
    start->next = new Node(2); 
    start->next->next = new Node(3); 
    start->next->next->next = new Node(4); 
    start->next->next->next->next = new Node(5); 
  
    // 1's random points to 3 
    start->random = start->next->next; 
  
    // 2's random points to 1 
    start->next->random = start; 
  
    // 3's and 4's random points to 5 
    start->next->next->random = 
                    start->next->next->next->next; 
    start->next->next->next->random = 
                    start->next->next->next->next; 
  
    // 5's random points to 2 
    start->next->next->next->next->random = 
                                      start->next; 
  
    cout << "Original list : \n"; 
    print_list(start);
  
    cout << "\nCloned list : \n"; 
    Node *cloned_list_head = cloned_list(start); 
    
    print_list(cloned_list_head);
  
    return 0; 
} 