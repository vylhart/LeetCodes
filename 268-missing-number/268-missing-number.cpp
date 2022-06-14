class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int> f(nums.size()+1, 0);
        for(int i: nums){
            f[i] = 1;
        }
        for(int i=0; i<nums.size()+1; i++){
            if(f[i]==0){
                return i;
            }
        }
        return -1;
        
    }
};