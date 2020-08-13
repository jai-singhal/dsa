// https://www.interviewbit.com/problems/merge-k-sorted-lists/
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

// * Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
 class comparator{
     public:
     bool operator()(pair<int, int> a, pair<int, int> b){
         return a.first > b.first;
     }
 };
ListNode* mergeKLists(vector<ListNode*> &A) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> min_heap;
    vector<ListNode*> heads;
    int i = 0;
    for(auto a: A){
        heads.push_back(a);
        pair<int, int> p = make_pair(a->val, i);
        min_heap.push(p);
        i++;
    }
    
    ListNode* head = NULL, *prev;
    while(!min_heap.empty()){
        pair<int, int> min_val = min_heap.top();
        min_heap.pop();

        ListNode* newNode = new ListNode(min_val.first);
        if(head == NULL)  head = newNode;
        else  prev->next = newNode;
        prev = newNode;

        if(heads[min_val.second]->next != NULL){
            heads[min_val.second] = heads[min_val.second]->next; 
            pair<int, int> p = make_pair(heads[min_val.second]->val, min_val.second);
            min_heap.push(p);
        }
    }
    prev->next = NULL;
    return head;
}
