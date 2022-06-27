class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> left, right, count;
        int MAX = 0;
        for(int i=0; i<nums.size(); i++){
            if(count[nums[i]]==0){
                left[nums[i]]=i;
                right[nums[i]]=i;
            }
            else{
                right[nums[i]]=i;
            }
            count[nums[i]]++;
            MAX = max(MAX, count[nums[i]]);
        }
        int ans = nums.size();
        cout<<MAX;
        for(auto i: count){
            if(i.second == MAX){
                ans = min(ans, right[i.first]-left[i.first]+1);
            }
        }
        return ans;
    }
};