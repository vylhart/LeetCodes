class Solution {
public:
    int twoEggDrop(int n) {
        vector<int> dp(n+1,0);
        for(int i=1; i<=n; i++){
            dp[i] = i;
            for(int j=1; j<i; j++){
                dp[i] = min(dp[i], 1+max(j-1, dp[i-j]));
            }
        }
        return dp[n];
    }
};