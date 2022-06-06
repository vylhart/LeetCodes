class Node{
    public:
    int val;
    Node* next;
    Node(int val){
        this->val = val;
        next=NULL;
    }
};


class MyLinkedList {
    Node *head, *tail;
public:
    MyLinkedList() {
        head = tail = NULL;
    }
    
    int get(int index) {
        int count=0;
        Node* curr = head;
        
        while(index!=count && curr){
            count++;
            curr = curr->next;
        }
        return curr ? curr->val : -1;  
    }
    
    void addAtHead(int val) {
        Node* node = new Node(val);
        if(head==NULL){
            head = tail = node;
        }
        else{
            node->next = head;
            head = node;
        }
        
    }
    
    void addAtTail(int val) {
        Node* node = new Node(val);
        if(head==NULL){
            tail = head = node;
        }
        else{
            tail->next = node;
            tail = node;
        }
    }
    
    void addAtIndex(int index, int val) {
        if(index==0){
            addAtHead(val);
            return;
        }
        
        int count = 0;
        Node* curr = head;
        while(curr && index-1 != count){
            count++;
            curr=curr->next;
        }
        
        if(curr){
            Node* node = new Node(val);
            if(curr == tail){
                tail = node;
            }
            node->next = curr->next;
            curr->next = node;
        }
        
    }
    
    void deleteAtIndex(int index) {
        if(index==0){
            if(head==NULL){
                
            }
            else if(head==tail){
                head=tail=NULL;
            }
            else{
                head = head->next;
            }
            return;
        }
        
        int count = 0;
        Node* curr = head;
        while(curr && index-1 != count){
            count++;
            curr=curr->next;
        }
        if(curr){
            if(tail==curr->next){
                tail = curr;
            }
            if(curr->next)
                curr->next = curr->next->next;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */