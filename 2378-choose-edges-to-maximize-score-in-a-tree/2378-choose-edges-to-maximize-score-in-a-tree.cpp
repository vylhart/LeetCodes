class Solution {
    unordered_map<int, int> map;
    vector<vector<pair<int,int>>> g;
public:
    pair<long,long> dfs(int i){
        long inc=0, exc=0, sum=0;
        for(int j=0; j<g[i].size(); j++){
            pair<long,long> p = dfs(g[i][j].first);
            inc = max(inc, g[i][j].second - max(p.first,p.second) + p.second);
            sum += max(p.first, p.second);
            exc = max({exc, p.first, p.second});
        }
        inc += sum;
        exc = max(exc, sum);
        //cout<<i<<inc<<exc<<endl;
        return {inc, exc};
    }
    
    
    long long maxScore(vector<vector<int>>& edges) {
        int n = edges.size();
        g.resize(n);
        for(int i=1; i<n; i++){
            g[edges[i][0]].push_back({i, edges[i][1]});
        }
        pair<long, long> p = dfs(0);
        return max(p.first, p.second);
    }
};