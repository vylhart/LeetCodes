class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> map;
        map[0]=1;
        int found=0, sum=0;
        for(int i=0; i<n; i++){
            sum= (sum+nums[i]%k)%k;

            found = map[sum];
            if(found){
                if(i-found>=0)  return 1;
            }
            else  map[sum]=i+2;
        }
        return 0;
    }
};