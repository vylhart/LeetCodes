class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> s;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0; i<(1<<n); i++){
            vector<int> tmp;
            for(int j=0; j<n; j++){
                if(i&(1<<j)){
                    tmp.push_back(nums[j]);
                }
            }
            s.insert(tmp);
        }
        return vector<vector<int>>(s.begin(), s.end());
    }
};