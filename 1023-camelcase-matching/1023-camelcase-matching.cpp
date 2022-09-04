class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        int m = pattern.length();
        for(string s: queries){
            int n = s.length();
            int i=0, j=0;
            bool found = 0;
            while(i<n && j<m){
                if(s[i]==pattern[j]){
                    s[i]='*';
                    j++;
                    if(j==m){
                        found=1;
                        break;
                    }
                }
                else{
                    i++;
                }
            }
            if(found){
                for(int i=0; i<n; i++){
                    if(s[i]>='A' && s[i]<='Z'){
                        found=0;
                        break;
                    }
                }
            }
            ans.push_back(found);
        }
        return ans;
    }
};