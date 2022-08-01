class Trie {
    class Node{
        public:
        bool isWord;
        Node* child[26];
    };
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* curr = root;
        for(char c: word){
            int x = c-'a';
            if(!curr->child[x]) curr->child[x]=new Node();
            curr = curr->child[x];
        }
        curr->isWord = 1;
    }
    
    bool search(string word) {
        Node* curr = root;
        for(char c: word){
            int x = c-'a';
            if(!curr->child[x]) return 0;
            curr = curr->child[x];
        }
        return curr->isWord;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for(char c: prefix){
            int x = c-'a';
            if(!curr->child[x]) return 0;
            curr = curr->child[x];
        }
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */