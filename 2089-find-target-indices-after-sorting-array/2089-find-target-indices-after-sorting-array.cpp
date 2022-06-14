class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int c=0,s=0;
        for(int i: nums){
            if(i==target)   c++;
            else if(i<target) s++;
        }
        vector<int> ans;
        for(int i=0; i<c; i++){
            ans.push_back(s);
            s++;
        }
        return ans;
    }
};