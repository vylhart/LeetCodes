class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        for(int i: nums){
            if(ans.size()==0 || i>ans[ans.size()-1]){
                ans.push_back(i);
            }
            else{
                int j = lower_bound(ans.begin(), ans.end(), i) - ans.begin();
                ans[j] = i; 
            }
        }
        return ans.size();
    }
};