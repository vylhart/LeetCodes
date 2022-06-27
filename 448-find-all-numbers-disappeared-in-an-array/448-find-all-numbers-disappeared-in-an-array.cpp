class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_map<int, int> map;
        for(int i: nums)    map[i]++;
        vector<int> ans;
        for(int i=1; i<=nums.size(); i++) if(map[i]==0) ans.push_back(i);
        return ans;
    }
};