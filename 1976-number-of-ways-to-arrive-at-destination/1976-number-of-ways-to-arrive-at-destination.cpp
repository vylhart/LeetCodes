class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        priority_queue<pair<long long, int>> q;
        long MOD = (int)1e9 + 7;
        vector<long long> dis(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        vector<vector<pair<int,long>>> v(n);
        for(auto i: roads){
            v[i[0]].push_back({i[1], i[2]});
            v[i[1]].push_back({i[0], i[2]});
        }
        q.push({0, 0});
        ways[0]=1;
        dis[0]=0;
        int ans=0;
        while(!q.empty()){
            int i = q.top().second;
            long long d = -q.top().first;
            q.pop();
            if(d>dis[i]) continue;
            for(auto j: v[i]){
                int k = j.first;
                long long w = j.second;
                if(w+d<dis[k]){
                    dis[k]=w+d;
                    ways[k] = ways[i];
                    q.push({-dis[k], k});
                }
                else if(w+d==dis[k]){
                    ways[k] = (ways[k]+ways[i])%MOD;
                }
            }
        }
        return ways[n-1];
    }
};