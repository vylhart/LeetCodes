class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        sort(v.begin(), v.end());
        int endtime = -1;
        int starttime = -1;
        vector<vector<int>> ans;
        for(auto i: v){
            if(i[0]<= endtime){
                endtime = max(endtime, i[1]);
            }
            else{
                if(starttime!=-1)
                    ans.push_back({starttime, endtime});
                starttime = i[0];
                endtime = i[1];
            }
        }
        ans.push_back({starttime, endtime});
        return ans;
        
    }   
};