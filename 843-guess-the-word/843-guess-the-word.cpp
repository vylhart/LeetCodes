class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        for (int i = 0; i < 10; ++i) {
            string& guessWord = wordlist[rand() % wordlist.size()];
            int guessMatch = master.guess(guessWord);
            
            vector<string> newlist;
            for (string& word : wordlist) {
                if (guessMatch == myMatch(word, guessWord)) {
                    newlist.push_back(word);
                }
            }
            wordlist = newlist;
        }
    }
    
private:
    int myMatch(string& word1, string& word2) {
        int cnt = 0;
        
        for (int i = 0; i < 6; ++i) {
            if (word1[i] == word2[i]) {
                ++cnt;
            }
        }
        
        return cnt;
    }
};