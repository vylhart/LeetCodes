class Solution {
public:
    void find(unordered_map<string,bool> &map, string s, string c, string st, int i, vector<string> &ans){
        if(i==s.length()){
            if(c=="")ans.push_back(st);
            return;
        } 
        c+=s[i];st+=s[i];
        find(map, s, c, st, i+1, ans);
        if(map[c]){
            if(i!=s.length()-1) st+=" ";
            find(map, s, "", st ,i+1, ans);
        }        
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> map;
        for(string st: wordDict)map[st]=1;
        vector<string> ans;
        find(map, s, "", "" , 0, ans);
        return ans;
    }
};