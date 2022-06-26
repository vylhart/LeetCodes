#define SIZE 1000
class MyHashMap {
public:

    class Node{
        public:
        Node *prev, *next;
        int key, value;
        Node(int key, int value){
            this->key = key;
            this->value = value;
            prev = next = NULL;
        }
    };
    
    int getHash(int key){
        for(int i=0; i<11; i++){
            key = (key*31 + 17)%SIZE;
        }
        return key;
    }
    
    class List{
        Node *head, *tail;
        public:
        List(){
            head = new Node(-1, -1);
            tail = head;
        }
        
        void add(Node* node){
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        
        Node* find(int key){
            Node* curr = head;
            while(curr){
                if(curr->key == key)    return curr;
                curr = curr->next;
            }
            return NULL;
        }
        
        void remove(Node* node){
            Node *prev = node->prev;
            if(tail==node)  tail = prev;
            node->prev->next = node->next;
            if(node->next) node->next->prev = prev;
        }
    };
    
    List *map[SIZE];
    
    MyHashMap() {
        for(int i=0; i<SIZE; i++)   map[i] = new List();
    }
    
    void put(int key, int value) {
        int hash = getHash(key);
        List *list = map[hash];
        Node *node = list->find(key);
        if(node){
            node->value = value;
            return;
        }
        node = new Node(key, value);
        list->add(node);
    }
    
    int get(int key) {
        int hash = getHash(key);
        List *list = map[hash];
        Node *node = list->find(key);
        if(!node) return -1;
        return node->value;
    }
    
    void remove(int key) {
        int hash = getHash(key);
        List *list = map[hash];
        Node *node = list->find(key);
        if(!node) return;
        list->remove(node);
    }
};