class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> v(nums.begin(), nums.end());
        int n = v.size();
        sort(v.begin(), v.end());
        int i=0,j=n-1;
        while(i<n && nums[i]==v[i]){
            i++;
        }
        while(j>=0 && nums[j]==v[j]){
            j--;
        }
        return max(0, j-i+1);
    }
};