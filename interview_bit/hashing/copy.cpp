
#include<iostream>
#include<map>
#include<vector>

using namespace std;

// Definition for singly-linked list.
struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
 
RandomListNode* copyRandomList(RandomListNode* A) {
    map<RandomListNode*, RandomListNode*> mapp;
    RandomListNode* temp = A;
    while(temp != NULL){
        RandomListNode* newNode = new RandomListNode(temp->label);
        mapp.insert({temp, newNode});
        temp = temp->next;
    }
    temp = A;
    RandomListNode* t;
    while(temp != NULL){
        t = mapp[temp];
        if(temp->next == NULL)
            t->next = NULL;
        else
            t->next = mapp[temp->next];
        if(temp->random == NULL)
            t->random = NULL;
        else
            t->random = mapp[temp->random];
        temp = temp->next;
    }
    return mapp[A];
}