class Solution {
public:
    int helper(int i, int sum, vector<int> &nums, int target){
        if(i==nums.size()){
            return sum==target;
        }
        return helper(i+1, sum+nums[i], nums, target)+helper(i+1, sum-nums[i], nums, target);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return helper(0, 0, nums, target);
    }
};