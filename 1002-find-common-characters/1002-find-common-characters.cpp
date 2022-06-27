class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        vector<int> freq(26, n);
        for(string s: words){
            vector<int> tmp(26, 0);
            for(char c: s){
                tmp[c-'a']++;
            }
            for(int i=0; i<26; i++){
                freq[i] = min(freq[i], tmp[i]);
            }
        }
        vector<string> ans;
        string s;
        for(int i=0; i<26; i++){
            while(freq[i]--){
                s = "";
                s+= ('a' + i);
                ans.push_back(s);
            }
        }
        
        return ans;
    }
};