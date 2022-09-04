class Solution {
public:
    int maxRepeating(string s, string w) {
        int n = s.length();
        int m = w.length();
        vector<int> lps(m,0),  dp(n,0);
        int ans = 0;
        int i=1, l=0;
        while(i<m){
            if(w[i]==w[l]){
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
        i=0;int j=0;
        while(i<n){
            if(s[i]==w[j]){
                j++;
                if(j==m){
                    dp[i]=1;
                    j=lps[j-1];
                }
                i++;
            }
            else{
                if(j==0){
                    i++;
                }
                else{
                    j=lps[j-1];
                }
            }
        }
        
        for(int i=0; i<n; i++){
            if(i-m>=0 && dp[i]){
                dp[i] = dp[i-m]+1;
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};