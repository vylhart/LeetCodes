class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0])  return -1;
        int move[8][2] = {{1,0}, {1,1}, {1,-1}, {0,1}, {0,-1}, {-1,0},{-1,-1}, {-1,1}};
        int n = grid.size();
        queue<vector<int>> q;
        q.push({0,0,1});
        grid[0][0]=1;
        while(!q.empty()){
            int x = q.front()[0];
            int y = q.front()[1];
            int d = q.front()[2];
            q.pop();
            if(x==n-1 &&y==n-1) return d;
            for(int k=0; k<8; k++){
                int u = x+move[k][0];
                int v = y+move[k][1];
                if(u>=0 && v>=0 && u<n && v<n && grid[u][v]==0){
                    q.push({u,v,d+1});
                    grid[u][v]=1;
                }
            }
        }
        return -1;
    }
};