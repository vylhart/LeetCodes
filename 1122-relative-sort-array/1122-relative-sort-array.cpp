class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans, tmp;
        unordered_map<int, int> map;
        for(int i: arr1){
            map[i]++;
        }
        for(int i: arr2){
            while(map[i]-->0){
                ans.push_back(i);
            }
        }
        for(auto i: map){
            while(map[i.first]-->0){
                tmp.push_back(i.first);   
            }
        }
        sort(tmp.begin(), tmp.end());
        ans.insert(ans.end(),tmp.begin(), tmp.end());
        return ans;
    }
};