void removeLoop(Node *head){
    unordered_map<Node*,bool> m;
    Node *temp=head;
    while(temp->next!=NULL && m[temp->next]==false){
        m[temp] = true;
        temp=temp->next;
    }
    temp->next=NULL;
}