
class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        vector<long> dp(n+1, 0);
        unordered_map<int, vector<pair<int,long>>> map;
        for(auto i: rides){
            map[i[1]].push_back({i[0], i[1]-i[0]+i[2]});
        }
        
        for(int i=1; i<=n; i++){
            for(auto &j: map[i]){
                dp[i] = max(dp[i], dp[j.first]+j.second);        
            }
            dp[i] = max(dp[i], dp[i-1]);
        }
        return dp[n];
        
    }
};