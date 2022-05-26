class Solution {
public:
    int numTilings(int n) {
        int mod = (int) 1e9+7;
        vector<long> dp(n+1, 0);
        vector<long> dpp(n+1, 0);
        dp[0]=1;
        for(int i=1; i<=n; i++){
            dp[i] = dp[i-1] + dpp[i-1];
            dpp[i]= dpp[i-1];
            if(i-2>=0){
                dp[i] += dp[i-2];
                dpp[i]+= 2*dp[i-2];
            }
            dpp[i]%=mod;
            dp[i]%=mod;
        }
        return dp[n];
    }
};