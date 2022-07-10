class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(2,0));
        for(int i=0; i<n; i++){
            dp[i][0] = s[i]!='0'; 
            if(i-1>=0)  dp[i][0] += dp[i-1][0];
            dp[i][1] = s[i]!='1';
            if(i-1>=0)  dp[i][1] += min(dp[i-1][0], dp[i-1][1]);
        }
        return min(dp[n-1][0], dp[n-1][1]);   
    }
};