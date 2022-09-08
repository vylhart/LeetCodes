class Solution {
public:
    string stoneGameIII(vector<int>& stone) {
        int n = stone.size();
        vector<int> dp(n,INT_MIN);
        for(int i=n-1; i>=0; i--){
            int s = 0;
            for(int j=1; j<=3 && i+j-1<n; j++){
                s += stone[i+j-1];
                dp[i] = max(dp[i], s-(i+j<n ? dp[i+j]: 0));
            }
        }
        return dp[0]>0 ? "Alice" : dp[0]==0 ? "Tie" : "Bob";
    }
};