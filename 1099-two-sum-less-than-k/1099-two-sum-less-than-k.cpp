class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = -1;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            int j = lower_bound(nums.begin(), nums.end(), k-nums[i]) - nums.begin();
            if(j==n || nums[i]+nums[j]>=k || i==j){
                if(j-1>=0 && i!=j-1)
                    ans = max(ans, nums[i]+nums[j-1]);
                else if(j-2>=0)
                    ans = max(ans, nums[i]+nums[j-2]);
            }
            else{
                ans = max(ans, nums[i]+nums[j]);
            }
        }
        return ans;
    }
};