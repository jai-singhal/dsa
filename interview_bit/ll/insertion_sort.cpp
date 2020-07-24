 // https://www.interviewbit.com/problems/insertion-sort-list/
 // * Definition for singly-linked list.
#include<iostream>
#include<string>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    // ListNode(int x) : val(x), next(NULL) {}
};
  
ListNode* insertionSortList(ListNode* head) {
    ListNode* it = head, *sit, *prev_sit, *prev_it;
    int swapval;
    
    if(head == nullptr || head->next == nullptr)
        return head;
    
    prev_it = it;
    it = it->next;
    while(it != nullptr){
        prev_sit = nullptr;
        sit = head;
        while(sit != nullptr && sit->val < it->val && sit != it){
            prev_sit = sit;
            sit = sit->next;
        }
        
        if(sit == head){
            head = it;
            prev_it->next = it->next;
            head ->next = sit;
        }
        else if(it != sit){
            prev_sit->next = it; 
            prev_it->next = it->next; //
            it->next = sit; //
        }   
        
        prev_it = it;
        it = prev_it->next;
    }
    return head;
}