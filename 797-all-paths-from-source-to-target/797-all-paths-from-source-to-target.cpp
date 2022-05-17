class Solution {
public:
    void dfs(vector<vector<int>> &v, int i, vector<int> &vis, vector<int> path, vector<vector<int>> &ans){
        path.push_back(i);
        if(i==vis.size()-1){
            ans.push_back(path);
            return;
        }
        vis[i]=1;
        for(int j: v[i]){
            if(!vis[j]){
                dfs(v, j, vis, path, ans);
            }
        }
        vis[i]=0;
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path, vis(graph.size(), 0);
        dfs(graph, 0, vis, path, ans);
        
        return ans;
    }
};