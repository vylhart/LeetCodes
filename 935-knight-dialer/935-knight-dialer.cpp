class Solution {
public:
    int knightDialer(int n) {
        int mod = (int) 1e9+7;
        vector<int> map[10] = {{4,6}, {6,8}, {7,9}, {4,8}, {3,9,0}, {}, {1,7,0}, {2,6}, {1,3}, {2,4}};
        vector<vector<int>> dp(n+1, vector<int>(10, 0));
        for(int i=1; i<=n; i++){
            for(int j=0; j<=9; j++){
                if(i==1){
                    dp[i][j]=1;
                    continue;
                }
                for(int k: map[j]){
                    dp[i][j] += dp[i-1][k];
                    dp[i][j] %= mod;
                }
            }
        }
        long ans = 0;
        for(int i=0; i<=9; i++){
            ans += dp[n][i];
            ans %= mod;
        }
        return ans;
        
    }
};