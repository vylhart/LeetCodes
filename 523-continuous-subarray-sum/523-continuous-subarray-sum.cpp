class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> map;
        map[0]=1;
        for(int i=0; i<n; i++){
            if(i==0)    nums[i] = nums[i]%k;
            else    nums[i] = (nums[i-1] + nums[i]%k)%k;
            
            if(map[nums[i]] && i-map[nums[i]]>=0)  
                return 1;
            else if(!map[nums[i]])
                map[nums[i]]=i+2;
        }
        
        return 0;
    }
};

/*
1 1
2 4 1 0  
*/