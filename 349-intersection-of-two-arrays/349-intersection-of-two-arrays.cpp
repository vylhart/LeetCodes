class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        for(int i: nums1){
            map[i]=1;
        }
        vector<int> ans;
        for(int i: nums2){
            if(map[i]){
                ans.push_back(i);
                map[i]=0;
            }
        }
        return ans;
    }
};