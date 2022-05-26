class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>> dp(n+2, vector<int>(n+2,0));
        
        for(int l=1; l<=n; l++){
            for(int i=1, j=i+l-1; i<=n && j<=n; i++,j++){
                //cout<<i<<j<<" ";
                for(int k=i; k<=j; k++){
                    int curr = nums[i-1]*nums[k]*nums[j+1];
                    int rem = dp[i][k-1] + dp[k+1][j];
                    dp[i][j] = max(curr + rem, dp[i][j]);
                }
            }
            //cout<<endl;
        }
        return dp[1][n];
    }
};