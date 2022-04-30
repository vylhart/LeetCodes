class Solution {
public:
    
    int partition(int l, int h, vector<int> &nums){
        int i=l, j=l;
        while(j<h){
            if(nums[j]>nums[h]){
                swap(nums[j], nums[i]);
                i++;
            }
            j++;
        }
        swap(nums[i], nums[h]);
        return i;
    }
    
    int divide(int l, int h, int k, vector<int> &nums){
        int p = partition(l, h, nums);
        if(p==k){
            return nums[p];
        }
        else if(p<k){
            return divide(p+1, h, k, nums);
        }
        return divide(l, p-1, k, nums);
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        return divide(0, nums.size()-1, k-1, nums);
    }
};