 // https://www.interviewbit.com/problems/k-reverse-linked-list/
 // * Definition for singly-linked list.

 // 4800
#include<iostream>
#include<string>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    // ListNode(int x) : val(x), next(NULL) {}
};
  

ListNode* reverseList(ListNode* A, int B) {
    ListNode *curr = A, *prev = NULL, *next = NULL;
    int cnt =0;
     while(cnt<B && curr) {
         next = curr->next;
         curr->next = prev;
         prev = curr;
         curr = next;
         cnt++;
     }
     if(next) {
         A->next = reverseList(next, B);
     }
     return prev;
}