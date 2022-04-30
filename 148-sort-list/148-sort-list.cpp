/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* merge(ListNode* a, ListNode* b){
        if(!a)  return b;
        if(!b)  return a;
        if(a->val < b->val){
            a->next = merge(a->next, b);
            return a;
        }
        b->next = merge(a, b->next);
        return b;
    }
    
    ListNode* getMid(ListNode* slow){
        ListNode* prev=0;
        ListNode* fast=slow;
        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next=0;
        return slow;
    }
    
    ListNode* divide(ListNode* a){
        if(!a || !a->next){
            return a;
        }
        ListNode* b = getMid(a);
        a = divide(a);
        b = divide(b);
        return merge(a,b);
    }
    
    ListNode* sortList(ListNode* head) {
        ListNode* start = head;
        return divide(head);
    }
};