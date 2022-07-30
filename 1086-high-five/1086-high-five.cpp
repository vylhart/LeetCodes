class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        unordered_map<int, priority_queue<int>> map;
        for(auto i: items){
            map[i[0]].push(-i[1]);
            if(map[i[0]].size()>5){
                map[i[0]].pop();
            }
        }
        vector<vector<int>> ans;
        for(auto &i: map){
            int sum=0;
            int n = i.second.size();
            while(!i.second.empty()){
                sum -= i.second.top(); i.second.pop();
            }
            ans.push_back({i.first, sum/n});
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};