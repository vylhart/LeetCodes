class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        bool found = false;
        for(int i=n-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                found = true;
                int index = i;
                for(int j=i+1; j<n; j++){
                    if(nums[i]<nums[j]){
                        index = j;
                    }
                }
                swap(nums[i],nums[index]);
                sort(nums.begin()+i+1 ,nums.end());
                break;
            }
            
        }
        if(!found){
            sort(nums.begin(), nums.end());
        }
    }
};