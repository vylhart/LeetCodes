class Solution {
public:
    vector<int> _lps(string s){
        int n = s.length();
        int l=0, i=1;
        vector<int> lps(n, 0);
        while(i<n){
            if(s[i]==s[l]){
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
        return lps;
    }
    
    string shortestPalindrome(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        vector<int> lps =  _lps(s);
        int i=0, j=0;
        int len = 0;
        int n = s.size();
        while(i<n && j<n){
            if(t[i]==s[j]){
                j++;
                if(i==n-1)
                    len=j;
                i++;
            }
            else{
                if(j>0){
                    j = lps[j-1];
                }
                else{
                    i++;
                }
            }
        }
        string tmp = "";
        for(int i=len; i<n; i++)    tmp += s[i];
        reverse(tmp.begin(), tmp.end());
        return tmp+s;
    }
};