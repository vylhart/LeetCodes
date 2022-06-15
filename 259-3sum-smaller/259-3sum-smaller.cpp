class Solution {
public:
    
    int countSmaller(vector<int> &v, int l, int h, int t){
        int ans=0;
        int i=l, j=h;
        while(i<j){
            while(i<j && v[i]+v[j]>=t){
                j--;
            }
            ans+= j-i;
            i++;
        }
        return ans;
    }
    
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int ans=0;
        for(int i=0; i<n-2; i++){
                ans+= countSmaller(nums, i+1, n-1, target-nums[i]);
        }
        return ans;
    }
};