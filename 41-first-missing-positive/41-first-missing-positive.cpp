class Solution {
public:
    int firstMissingPositive(vector<int>& v) {
        vector<int> nums;
        for(int i:v)    if(i>0 && i<=v.size()) nums.push_back(i);
        if(nums.size()==0)  return 1;
        
        
        unordered_map<int, int> map;
        int ans=0, m=nums[0];
        for(int i:nums){
            map[i]++;
            ans = max(ans,i+1);
            m = min(i, m);
        }
        if(m>1) return 1;

        for(int i:nums){
            if(i-1>0 && !map[i-1] && ans>i-1){
                ans = i-1;
            }
            if(!map[i+1] && ans>i+1){
                ans = i+1;
            }
        }
        return ans;
    }
};