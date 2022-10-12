class WordDictionary {
    class Node{
        public:
        bool isLeaf;
        Node* child[26];
        Node(){
            isLeaf = 0;
            for(int i=0; i<26; i++) child[i]=0;
        }
    };
    Node* root;    
    public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* curr = root;
        for(char c: word){
            if(!curr->child[c-'a']){
                curr->child[c-'a'] = new Node();
            }
            curr = curr->child[c-'a'];
        }
        curr->isLeaf = 1;
    }
    
    bool search(string &word, int i, Node* curr){
        if(!curr)   return 0;
        if(i==word.length()){
            return curr->isLeaf;
        }
        char c = word[i];
        //cout<<c;
        if(c=='.'){
            for(int j=0; j<26; j++){
                if(curr->child[j] && search(word, i+1, curr->child[j])){
                    return 1;
                }
            }
        }
        else{
            if(curr->child[c-'a'])
            return search(word, i+1, curr->child[c-'a']);
        }
        return 0;
    }
    
    bool search(string word) {
        return search(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */