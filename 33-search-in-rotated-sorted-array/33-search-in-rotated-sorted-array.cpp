class Solution {
    int n;
public:
    int findPeak(vector<int> &nums, int t){
        if(nums[0]<nums[n-1])   return n-1;
        int l=0, h=n-1;
        while(l<=h){
            int m = l+(h-l)/2;
            if((m==0  || nums[m-1] < nums[m]) && (m==n-1 || nums[m]>nums[m+1]) ){
                return m;
            }
            else if(nums[m]>nums[n-1]){
                l = m+1;
            }
            else{
                h = m-1;
            }
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        n = nums.size();
        int l,h;
        int peak = findPeak(nums, target);
        if(target>=nums[0]){
            l=0; h=peak;
        }
        else{
            l=peak+1, h=n-1;
        }
        while(l<=h){
            int m = l+(h-l)/2;
            if(nums[m]==target) return m;
            else if(nums[m]<target) l=m+1;
            else    h = m-1;
        }
        return -1;
    }
};