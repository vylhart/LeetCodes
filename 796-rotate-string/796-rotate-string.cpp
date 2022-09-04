class Solution {
public:
    
    
    bool rotateString(string s, string p) {
        if(p.length()!=s.length())  return 0;
        s += s;
        int n = s.length();
        int m = p.length();
        
        int i=1, l=0;
        vector<int> lps(m,0);
        while(i<m){
            if(p[i]==p[l]){
                lps[i++]=++l;
            }
            else{
                if(l>0){
                    l = lps[l-1];
                }
                else{
                    i++;
                }
            }
        }
        i=0;int j=0;
        while(i<n){
            if(s[i]==p[j]){
                i++;j++;
                if(j==m)    return 1;
            }
            else{
                if(j==0)    i++;
                else    j = lps[j-1];
            }
        }
        return 0;
        
        
    }
};