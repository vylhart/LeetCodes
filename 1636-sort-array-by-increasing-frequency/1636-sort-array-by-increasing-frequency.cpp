class Solution {
public:
    static bool compare(pair<int,int> a, pair<int, int> b){
        if(a.second == b.second){
            return a.first>b.first;
        }
        return a.second < b.second;
    }
    
    vector<int> frequencySort(vector<int>& nums) {
        vector<pair<int, int>> v;
        unordered_map<int,int> map;
        for(int i: nums)    map[i]++;
        for(auto i: map){
            v.push_back(i);
        }
        sort(v.begin(), v.end(), compare);
        vector<int> ans;
        for(auto i: v){
            for(int j=0; j<i.second; j++){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};