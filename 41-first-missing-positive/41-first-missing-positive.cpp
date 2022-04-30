class Solution {
public:
    int firstMissingPositive(vector<int>& v) {
        vector<int> nums;
        for(int i:v)    if(i>0) nums.push_back(i);
        unordered_map<long, int> map;
        if(nums.size()==0)  return 1;
        
        
        
        long ans=0, m=nums[0];
        for(int i:nums){
            if(i<=0)    continue;
            map[i]++;
            ans = max(ans,(long)i+1);
            m = min((long)i, m);
        }
        if(m>1) return 1;
        if(ans<=0)  return 1;
        for(long i:nums){
            if(i<=0)    continue;
            if(i-1>0 && !map[i-1] && ans>i-1){
                ans = i-1;
            }
            if(i+1>0 && !map[i+1] && ans>i+1){
                ans = i+1;
            }
        }
        return ans;
    }
};