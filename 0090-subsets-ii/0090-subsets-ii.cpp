class Solution {
    vector<vector<int>> ans;
    vector<int> nums;
    int n;
public:
    void find(int i, vector<int> &v){
        if(i==n){
            ans.push_back(v);
            return;
        }
        v.push_back(nums[i]);
        find(i+1, v);
        v.pop_back();
        while(i+1<n && nums[i]==nums[i+1])  i++;
        find(i+1, v);
    }
    
    
    vector<vector<int>> subsetsWithDup(vector<int>& _nums) {
        nums = _nums;
        n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> tmp;
        find(0, tmp);
        return ans;
    }
};