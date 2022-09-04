class Solution {
public:
    int strStr(string s, string p) {
        int n =s.length();
        int m =p.length();
        vector<int> lps(m,0);
        int i=1, j=0, l=0;
        while(i<m){
            if(p[i]==p[l]){
                lps[i++]=++l;
            }
            else{
                if(l==0)    i++;
                else    l=lps[l-1];
            }
        }
        i=0;
        while(i<n){
            if(s[i]==p[j]){
                j++;
                i++;
                if(j==m){
                    return i-m;
                }
            }
            else{
                if(j==0) i++;
                else    j=lps[j-1];
            }
        }
        return -1;
    }
};