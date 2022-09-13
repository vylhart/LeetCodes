/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    unordered_map<Node*, Node*> map;
public:
    Node* copyRandomList(Node* head) {
        Node* nhead = 0;
        Node* prev = 0;
        for(Node* curr = head; curr; curr=curr->next){
            Node* node = new Node(curr->val);
            if(!nhead){
                nhead = node;
            }
            else{
                prev->next = node;
            }
            map[curr] = node;
            prev = node;
        }
        for(Node* curr = head; curr; curr=curr->next){
            map[curr]->random = map[curr->random];
        }
        return nhead;
    }
};