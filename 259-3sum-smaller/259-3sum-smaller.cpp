class Solution {
public:
    
    int countSmaller(vector<int> &v, int l, int h, int t){
        int ans=0;
        int ll=l;
        while(l<=h){
            int m = l+(h-l)/2;
            if(v[m]<t){
                ans = m-ll+1;
                l = m+1;
            }
            else{
                h = m-1;   
            }
        }
        return ans;
    }
    
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int ans=0;
        for(int i=0; i<n-2; i++){
            for(int j=i+1; j<n-1; j++){
                ans+= countSmaller(nums, j+1, n-1, target-nums[i]-nums[j]);
            }
        }
        return ans;
    }
};