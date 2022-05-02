class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> map;
        map[0]=1;
        int found=0;
        for(int i=0; i<n; i++){
            if(i==0)    nums[i] = nums[i]%k;
            else    nums[i] = (nums[i-1] + nums[i]%k)%k;
            
            found = map[nums[i]];
            if(found){
                if(i-found>=0)  return 1;
            }
            else  map[nums[i]]=i+2;
        }
        return 0;
    }
};