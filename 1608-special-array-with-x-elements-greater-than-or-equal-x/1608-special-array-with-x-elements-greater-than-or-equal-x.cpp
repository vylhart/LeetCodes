class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int MIN = -1;
        int right = n;
        for(int i: nums){
            if(MIN < right && right<= i){
                return right;
            }
            MIN = i;
            right--;
        }
        return -1;
    }
};