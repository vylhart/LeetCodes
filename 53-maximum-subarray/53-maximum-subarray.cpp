class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_here=(int)-1e5;
        int max_all = max_here;
        for(int i: nums){
            max_here = max(i, i+max_here);
            max_all = max(max_here, max_all);
            //cout<<max_here<<" ";
        }
        return max_all;
    }
};