class Solution {
    unordered_set<string> set;
public:
    
    bool check(string &s, string &p){
        int n = s.length();
        int m = p.length();
        for(int i=0; i<n; i++){
            int t=0;
            while(i<n && t<m && s[i+t]==p[t])   t++;
            if(t==m){
                set.insert(p);
                return 1;
            }
        }
        return 0;
    }
    
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(words[i].length()<=words[j].length()){
                    check(words[j], words[i]);
                }
                else{
                    check(words[i], words[j]);
                }
            }
        }
        return vector<string>(set.begin(), set.end());
    }
};