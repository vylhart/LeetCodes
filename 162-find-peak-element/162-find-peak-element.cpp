class Solution {
public:
    long get(vector<int> &nums, int i){
        if(i==-1 || i==nums.size()) return LONG_MIN;
        return nums[i];
    }
    
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l=0, h=n-1;
        while(l<=h){
            int m = l+(h-l)/2;
            if(get(nums, m-1)<get(nums, m) && get(nums, m)>get(nums, m+1)){
                return m;
            }
            else if(get(nums, m-1)<get(nums, m) && get(nums, m)<get(nums, m+1)){
                l = m+1;   
            }
            else{
                h = m-1;
            }
        }
        return -1;
    }
};