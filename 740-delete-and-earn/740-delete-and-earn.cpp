class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int> map;
        for(int i:nums) map[i]+=i;
        vector<int> v;
        for(auto i: map)    v.push_back(i.first);
        int n = v.size();
        vector<int> dp(n, 0);
        sort(v.begin(), v.end());
        
        for(int i=0; i<n; i++){
            dp[i] = map[v[i]];
            if(i-1>=0 && v[i-1]<v[i]-1)  dp[i] += dp[i-1];
            else if(i-2>=0) dp[i] += dp[i-2];
            if(i-1>=0)  dp[i] = max(dp[i], dp[i-1]);
        }
        return dp[n-1];
    }
};