class Solution {
public:
    int uniquePaths(int m, int n) {
        long mod = 2e9;
        long dp[m+n-1][m+n-1];
        for(int i=0; i<m+n-1; i++){
            for(int j=0; j<m+n-1; j++){
                dp[i][j]=1;
            }
        }
        for(int i=1; i<m+n-1; i++){
            for(int j=0; j<=i; j++){
                if(j==0||j==i)    
                    dp[i][j]=1;
                else
                    dp[i][j] = (dp[i-1][j]+dp[i-1][j-1])%mod;
            }
        }
        return dp[m+n-2][min(n,m)-1];
        
    }
};
