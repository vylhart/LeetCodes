class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int n = nums.size();
        int i  = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int j  = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        if(i==n || nums[i]!=target || j-i<=n/2) return 0;
        return 1;
    }
};