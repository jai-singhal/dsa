// https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list/
 // * Definition for singly-linked list.
#include<iostream>
#include<string>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    // ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    ListNode* curr = head, *prev = head;
    curr = curr->next;
    while(curr != nullptr){
        if(prev->val == curr->val){
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }
        else{
            curr = curr->next;
            prev = prev->next;
        }
    }
}