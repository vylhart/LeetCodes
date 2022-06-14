class Solution {
    int n,m;
    int move[4][2] = {{0,1}, {1,0}, {-1,0}, {0,-1}};
public:
    
    bool safe(int i, int j){
        return i>=0 && j>=0 && i<n && j<m;
    }
    
    int countPerimeter(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &vis){
        int count = 0;
        vis[i][j]=1;
        for(int k=0; k<4; k++){
            int u = i+move[k][0];
            int v = j+move[k][1];
            if(!safe(u,v) || grid[u][v]==0)  count++;
            else if(vis[u][v]==0){
                count+= countPerimeter(u, v, grid, vis);
            }
        }
        return count;
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0) );
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j]==1){
                    ans += countPerimeter(i, j, grid, vis);
                }
            }
        }
        return ans;
        
    }
};