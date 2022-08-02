class Solution {
public:
    
    string sortSentence(string s) {
        int l = s.length();
        vector<pair<int,string>> ans;
        string tmp="";
        for(int i=0; i<l; i++){
            if(s[i]==' ') continue;
            else if(s[i]>='0' && s[i]<='9'){
                ans.push_back({s[i]-'a', tmp});
                tmp = "";
            }
            else{
                tmp += s[i];
            }
        }
        sort(ans.begin(), ans.end());
        string t="";
        for(int i=0; i<ans.size(); i++){
            t+= ans[i].second;
            if(i<ans.size()-1)  t+=" ";
        }
        
        return t;
        
    }
};