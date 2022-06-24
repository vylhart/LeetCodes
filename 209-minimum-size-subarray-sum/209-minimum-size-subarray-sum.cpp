class Solution {
public:
    int minSubArrayLen(int target, vector<int>& v) {
        int n = v.size();
        vector<long> nums(v.begin(), v.end());
        for(int i=1; i<n; i++)  nums[i]+=nums[i-1];
        int i=0,j=-1;
        int ans = n+1;
        while(i<n){
            //j = max(j, i-ans);
            while(j<i && nums[i]>=target+ (j==-1 ? 0: nums[j])){
                ans = min(ans, i-j);
                j++;
            }
            i++;    
        }
        return ans==n+1?0:ans;
        
    }
};