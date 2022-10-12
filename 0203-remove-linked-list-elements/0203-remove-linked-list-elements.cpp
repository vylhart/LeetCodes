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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* tmp = new ListNode(-1);
        tmp->next = head;
        ListNode* curr = tmp;
        ListNode* prev= 0;
        while(curr){
            if(curr->val == val){
                prev->next = curr->next;
            }
            else{
                prev = curr;
            }
            curr = curr->next;
        }
        return tmp->next;
    }
};