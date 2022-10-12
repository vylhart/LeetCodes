class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)  return nums[0];
        int ans = 0;
        int inc=0,exc=0;
        int n = nums.size();
        for(int i=0; i<n-1; i++){
            int tmp = exc;
            exc = max(inc, exc);
            inc = nums[i]+tmp;
        }
        ans = max(inc, exc);
        inc=0;exc=0;
        for(int i=1; i<n; i++){
            int tmp = exc;
            exc = max(inc, exc);
            inc = nums[i]+tmp;
        }
        ans = max(ans, max(inc, exc));
        return ans;
    }
};