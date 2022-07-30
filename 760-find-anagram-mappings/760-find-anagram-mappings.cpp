class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, stack<int>> map;
        for(int i=0; i<nums2.size(); i++){
            map[nums2[i]].push(i);
        }
        vector<int> ans;
        for(int i: nums1){
            ans.push_back(map[i].top());
            map[i].pop();
        }
        return ans;
    }
};