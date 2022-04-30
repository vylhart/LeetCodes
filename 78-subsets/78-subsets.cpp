class Solution {
public:
    void find(vector<vector<int>> &ans, vector<int> curr, int i, vector<int> &nums){
        if(i>=nums.size()){
           ans.push_back(curr);
            return;
        }  
        find(ans, curr, i+1, nums);
        if(curr.size()==0 || curr[curr.size()-1]!=nums[i]){
            curr.push_back(nums[i]);
            find(ans, curr, i+1, nums);
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        find(ans, curr, 0, nums);
        return ans;
    }
};