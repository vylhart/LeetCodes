class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int>  sum(n,0);
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        for(int i=n-1; i>=0; i--){
            sum[i]=piles[i];
            if(i+1<n)   sum[i]+=sum[i+1];
        }
        
        for(int i=n-1; i>=0; i--){
            for(int m=1; m<=n; m++){
                for(int x=1; x<=2*m && i+x<=n; x++){
                    if(m==n)    dp[i][m] = max(dp[i][m], sum[i]);
                    else dp[i][m] = max(dp[i][m], sum[i]-dp[i+x][max(x,m)]);
                }
            }
        }
        return dp[0][1];
    }
};