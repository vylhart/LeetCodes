/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    int match(string &a, string &b){
        int c = 0;
        for(int i=0; i<6; i++){
            if(a[i]==b[i])  c++;
        }
        return c;
    }
    
    void findSecretWord(vector<string>& wordlist, Master& master) {
        for(int i=0; i<10; i++){
            string &guess = wordlist[rand()% wordlist.size()];
            int x = master.guess(guess);
            vector<string> tmp;                              
            for(string &word: wordlist){
                if(x==match(guess, word)){
                    tmp.push_back(word);
                }
            }
            wordlist = tmp;
        }
    }
};