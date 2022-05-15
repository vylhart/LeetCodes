class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        stack<int> s;
        nums.push_back(-1);
        int ans=0;
        for(int i=0; i<nums.size(); i++){
            while(!s.empty() && nums[s.top()]>nums[i]){
                ans+= i-s.top();
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};