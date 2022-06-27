class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, char> map;
        char x = 'a';
        for(char  c: order){
            map[c] = x;
            x++;
        }
        
        for(int j=0; j<words.size(); j++){
            for(int i=0; i<words[j].length(); i++){
                words[j][i] = map[words[j][i]];
            }
        }
        
        for(int i=1; i<words.size(); i++){
            if(words[i-1]>words[i]) return 0;
        }
        return 1;
    }
};