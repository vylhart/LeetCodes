class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> dp(n+1, 0);
        dp[1]=1;
        for(int i=2; i<=n; i++){
            for(int j=1; i-j*j>=0; j++){
                if(dp[i-j*j]==0){
                    dp[i]=1;
                    break;
                }
            }
        }
        return dp[n];
    }
};