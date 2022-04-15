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
    void reverse(ListNode* head, int n, ListNode* &ahead){
        //cout<<head->val;
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next;
        while(n-- && curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        if(!ahead)       ahead = prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *currGroup = head;
        ListNode *prevGroup = NULL;
        head = NULL;
        
        while(currGroup){
            ListNode* curr = currGroup;
            ListNode* end  = currGroup;
            int n = k-1;
                //cout<<curr->val;
            while(n && end->next){
                end = end->next;
                n--;
            }
            
            if(prevGroup)   prevGroup->next = end;
            if(n>0){
                prevGroup->next = curr;
            }
            prevGroup = curr;
            currGroup = end->next;
            if(n==0)
                reverse(curr, k, head);

        }
        return head;
    }
};