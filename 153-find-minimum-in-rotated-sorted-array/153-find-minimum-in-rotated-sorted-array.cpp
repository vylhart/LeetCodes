class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(nums[0]<nums[n-1])   return nums[0];
        int l=0, h=n-1;
        while(l<=h){
            int m = l+(h-l)/2;
            cout<<m;
            if((m==0 || nums[m-1]>nums[m])  && (m==n-1 || nums[m]<nums[m+1])){
                return nums[m];
            }
            else if(nums[m]>nums[n-1]){
                l=m+1;
            }
            else{
                h=m-1;
            }
        }
        return -1;
    }
};