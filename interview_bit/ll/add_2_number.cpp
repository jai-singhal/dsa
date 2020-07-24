// https://www.interviewbit.com/problems/add-two-numbers-as-lists/
#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
  

ListNode* addTwoNumbers(ListNode* A, ListNode* B) {
    ListNode* t1 = A, *t2 = B, *sumhead = nullptr, *sumtemp = nullptr, *newNode;
    int carry = 0, sum = 0;
    while(t1 != nullptr && t2 != nullptr){
        sum = (carry + t1->val+t2->val)%10;
        newNode = new ListNode(sum);
        if(sumhead == nullptr)
            sumhead = newNode;
        else{
            sumtemp->next = newNode; 
        }
        sumtemp = newNode;
        carry = floor((t1->val + t2->val + carry) / 10);
        t1 = t1->next;
        t2 = t2->next;
    }
    while(t1 != nullptr){
        sum = (carry + t1->val)%10;
        newNode = new ListNode(sum);
        if(sumhead == nullptr)
            sumhead = newNode;
        else{
            sumtemp->next = newNode; 
        }
        sumtemp = newNode;
        carry = floor((t1->val + carry) / 10);
        t1 = t1->next;
    }
    
    while(t2 != nullptr){
        sum = (carry + t2->val)%10;
        newNode = new ListNode(sum);
        if(sumhead == nullptr)
            sumhead = newNode;
        else{
            sumtemp->next = newNode; 
        }
        sumtemp = newNode;
        carry = floor((t2->val + carry) / 10);
        t2 = t2->next;
    }
    
    if(carry){
        newNode = new ListNode(carry);
        sumtemp->next = newNode; 
    }
    
    return sumhead;
}