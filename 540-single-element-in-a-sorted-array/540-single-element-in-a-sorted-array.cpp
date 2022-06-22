class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n==1)    return nums[0];
        int l=0, h=n-1;
        int ans = -1;
        while(l<=h){
            int m = l+(h-l)/2;
            if((m%2==0 && (m+1!=n && nums[m]==nums[m+1])) || (m%2!=0 && m!=0 && nums[m]==nums[m-1])){
                l = m+1;
            }
            else{
                ans = nums[m];
                h = m-1;
            }
        }
        return ans;
        
    }
};