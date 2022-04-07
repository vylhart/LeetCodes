class Solution {
public:
    int NOT_VISITED = 0;
    int IN_PROGRESS = 1;
    int VISITED = 2;
    bool dfs(int i, vector<int> &vis, vector<vector<int>> &g){
        if(vis[i]==VISITED) return 0;
        vis[i]=1;
        for(int j: g[i]){
            if(vis[j]==IN_PROGRESS){
                return 1;
            }
            if(dfs(j, vis, g))  return 1;
        }
        vis[i]=VISITED;
        return 0;
    }
    
    
    bool canFinish(int n, vector<vector<int>>& prer) {
        vector<vector<int>> g(n);
        for(auto i: prer){
            g[i[1]].push_back(i[0]);
        }
        vector<int> vis(n, NOT_VISITED); 
        for(int i=0; i<n; i++){
            if(dfs(i, vis, g))  return 0;
        }
        return 1;
    }
};