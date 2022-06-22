class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        int i=-1, j=0;
        int ans = 0;
        while(i<n && j<n){
            count += nums[j]==0;
            while(i<=j && count>k){
                i++;
                count -= nums[i]==0;
            }
            ans = max(ans, j-i);
            j++;
        }
        return ans;
    }
};