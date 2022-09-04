class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        int i=1, l=0;
        vector<int> lps(n,0);
        
        while(i<n){
            if(s[i]==s[l]){
                lps[i++]=++l;
            }
            else{
                if(l==0){
                    i++;
                }
                else{
                    l = lps[l-1];
                }
            }
        }
        return l!=0 && n%(n-l)==0;
    }
};