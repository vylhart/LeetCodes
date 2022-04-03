
class Solution {
public:
    int move[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    int n,m;
    bool safe(int i, int j, vector<vector< bool >> &vis, vector<vector<char>> &grid){
        return i>=0 && j>=0 && i<n && j<m && !vis[i][j] && grid[i][j]=='1';
    }
    
    void dfs(int i, int j, vector<vector<bool>> &vis, vector<vector<char>> &grid){
        vis[i][j]=1;
        for(int k=0; k<4; k++){
            int u = i+move[k][0];
            int v = j+move[k][1];
            if(safe(u,v,vis, grid))   dfs(u,v,vis, grid);
        }
    }
    
    int numIslands(vector<vector<char>> &grid) {
        n = grid.size();
        m = grid[0].size();
        int ans=0;
        vector<vector<bool>> vis(n, vector<bool>(m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(safe(i,j,vis, grid)){
                    ans++;
                    dfs(i, j, vis, grid);
                }
            }
        }
        return ans;    
    }
};