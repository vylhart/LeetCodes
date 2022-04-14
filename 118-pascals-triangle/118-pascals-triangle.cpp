class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> v(n);
        vector<vector<int>> dp(n, vector<int>(n,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<n-i; j++){
                if(i==0||j==0)  
                    dp[i][j]=1;
                else
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                v[i+j].push_back(dp[i][j]);
            }
        }  
        return v;
    }
};





/*

*/