/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* hare = head;
        ListNode* turtle = head;
        while(hare && hare->next && turtle){
            turtle = turtle->next;
            hare = hare->next->next;
            if(turtle==hare) return 1;
        }
        return 0;
    }
};