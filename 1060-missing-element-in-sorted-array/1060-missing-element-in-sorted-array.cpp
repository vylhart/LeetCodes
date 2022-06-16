class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        nums.push_back(INT_MAX);
        int n = nums.size();
        int l = 0, h = n-1;
        int ans = -1;
        while(l<=h){
            int m = l+(h-l)/2;
            if(nums[m]-nums[0]-m>=k){
                ans = m;
                h = m-1;
            }
            else{
                l = m+1;
            }
        }
        return nums[0]+ans-1+k;
        
    }
};