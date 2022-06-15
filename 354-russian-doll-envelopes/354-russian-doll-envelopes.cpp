class Solution {
public:
    static bool compare(vector<int> &a, vector<int> &b){
        if(a[0]==b[0]) return a[1]>b[1];
        return a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& e) {
        sort(e.begin(), e.end(), compare);
        vector<int> lis;
        for(auto &i: e){
            auto it = lower_bound(begin(lis), end(lis), i[1]);
            if(it==lis.end())   lis.push_back(i[1]);
            else{
                *it = i[1];
            }
        }
        return lis.size();
    }
};

// 3 4 7 4