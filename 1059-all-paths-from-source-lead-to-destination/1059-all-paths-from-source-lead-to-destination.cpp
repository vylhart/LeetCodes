class Solution {
public:
    bool dfs(vector<vector<int>> &v, int s, int d, vector<int> &vis){
        if(v[s].size()==0){
            return s==d;
        }
        vis[s]=1;
        for(int i: v[s]){
            if(vis[i]==1)   return false;
            if(vis[i]==0 && !dfs(v, i, d, vis)){
                return false;
            }
        }
        vis[s]=2;
        return true;
    }
    
    
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> g(n);
        for(auto i: edges){
            g[i[0]].push_back(i[1]);
        }
        vector<int> vis(n,0);
        return dfs(g, source, destination, vis);        
    }
};