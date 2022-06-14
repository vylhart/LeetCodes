class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int i = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        vector<int> ans;
        while(i<nums.size() && nums[i]==target){
            ans.push_back(i);
            i++;
        }
        return ans;
    }
};