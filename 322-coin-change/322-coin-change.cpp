class Solution {
public:
    int coinChange(vector<int>& nums, int sum) {
        int n = nums.size();
        vector<long> dp(sum+2, sum+1);
        for(int i: nums)  if(i<=sum)  dp[i]=1;
        dp[0]=0;
        for(int i: nums){
            for(int j=i; j<=sum; j++){
                dp[j] = min(dp[j], dp[j-i]+1);
            }
        }
        return dp[sum]>=sum+1?-1:dp[sum];
    }
};